#include "codeGenerator.h"
#include "AST_parser.hpp"

#define INDENT 4

extern int yyparse();
extern BlockExprNode* root;

string modify_funcname(string name) {
    /*if(name == "strlen") {
        return "len";
    }
    else */
    if (name == "isdigit") {
        return "str.isdigit";
    } 
    return name;
}

BaseGeneratorBlock::BaseGeneratorBlock() {
    isFunction = false;
}

GeneratorContext::GeneratorContext() {
    funcDeclaring = false;
    indent_num = 0;
    blocks.push(new BaseGeneratorBlock());
}

GeneratorContext::~GeneratorContext() {

}

void GeneratorContext::codeGenerator(BlockExprNode &root) {
    codeOutput << "# -*- coding:utf-8" << endl;
    codeOutput << "# Project: Compiler final project" << endl;
    codeOutput << "def printf(format, *args):" << endl;
    codeOutput << "    if len(args):" << endl;
    codeOutput << "        print ((\"\b\"+format) % tuple(args))," << endl;
    codeOutput << "    else:" << endl;
    codeOutput << "        print (\"\b\"+format)," << endl;
    codeOutput << endl;
    codeOutput << "def scanf(format, arg):" << endl;
    codeOutput << "    temp_str = input()" << endl;
    codeOutput << "    for i in range(len(temp_str)):" << endl;
    codeOutput << "        arg[i] = temp_str[i]" << endl;
    codeOutput << endl;
    codeOutput << "def strlen(char_list):" << endl;
    codeOutput << "    result = 0" << endl;
    codeOutput << "    for i in range(len(char_list)):" << endl;
    codeOutput << "        if not char_list[i]:" << endl;
    codeOutput << "            break;" << endl;
    codeOutput << "        result += 1" << endl;
    codeOutput << "    return result" << endl;
    codeOutput << endl;
    codeOutput << "def atoi(clist):" << endl;
    codeOutput << "    newlist = []" << endl;
    codeOutput << "    for item in clist:" << endl;
    codeOutput << "        if not item:" << endl;
    codeOutput << "            break" << endl;
    codeOutput << "        newlist.append(item)" << endl;
    codeOutput << "    return float(''.join(newlist))" << endl;
    codeOutput << endl;
    root.codeGenerator(*this);
    codeOutput << "\nif __name__ == \"__main__\":\n    main()\n";
}

void GeneratorContext::outputCode(ostream& out) {
    out << codeOutput.str();
}

void GeneratorContext::clearBuf() {
    codeBuffer.str("");
}

void GeneratorContext::applyBuf() {
    codeOutput << codeBuffer.str();
    clearBuf();
}

set<string>& GeneratorContext::locals() {
    return blocks.top()->locals;
}

set<string>& GeneratorContext::declaredGlobals() {
    return blocks.top()->declaredGlobals;
}

set<string>& GeneratorContext::globals() {
    return globalVariables;
}

BaseGeneratorBlock* GeneratorContext::currentBlock() {
    return blocks.top();
}

void GeneratorContext::pushBlock(bool copyLocals, bool isFunction) {
    BaseGeneratorBlock* block = new BaseGeneratorBlock();
    if(copyLocals) {
        block->locals = blocks.top()->locals;
    }
    if(!isFunction) {
        block->declaredGlobals = blocks.top()->declaredGlobals;
    }
    block->isFunction = isFunction;
    blocks.push(block);
    indent_num = indent_num + INDENT;
}

void GeneratorContext::popBlock() {
    BaseGeneratorBlock *top = blocks.top();
    blocks.pop();   
    indent_num = indent_num - INDENT;
    delete top;
}

void GeneratorContext::indent(bool buf) {
    for(int i = 0; i < indent_num; i++) {
        if(buf) {
            codeBuffer << ' ';
        }
        else {
            codeOutput << ' ';
        }
    }
}

void GeneratorContext::declareGlobal(string name) {
    codeOutput << "global " << name;
}

void GeneratorContext::nextLine(bool buf) {
    if(buf) {
        codeBuffer << '\n';
    }
    else {
        codeOutput << '\n';
    }
}

void VariableExprNode::codeGenerator(GeneratorContext &context){
    if(context.funcDeclaring) {
        if(context.globals().count(name) > 0) {
            fprintf(stderr, "重复命名 %s\n", name.c_str());
        }
        else {
            context.locals().insert(name);
            context.codeOutput << name;
        }
    }
    else {
        if(context.locals().count(name) > 0) {
            context.codeBuffer << name;
        }
        else if (context.globals().count(name) > 0){
            if (context.declaredGlobals().count(name) > 0) {
                context.codeBuffer << name;
            }
            else {
                context.declaredGlobals().insert(name);
                context.codeBuffer << name;
            }
        }
        else {
            fprintf(stderr, "未声明的变量 %s\n", name.c_str());
        }
    }
}

void CharExprNode::codeGenerator(GeneratorContext &context) {
    if (val == '\'' || val == '\\') {
        context.codeBuffer << "\'\\" << val << "\'";
    }
    else {
        context.codeBuffer << "\'" << val << "\'";
    }
}

void StringExprNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << "\"" << cstr << "\"";
}

void IntExprNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << val;
}

void DoubleExprNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << val;
}

void BlockExprNode::codeGenerator(GeneratorContext &context) {
    cout << context.codeBuffer.str() << endl;
    cout << context.codeOutput.str() << endl;
    if (statements->size() == 0) {
        context.indent(true);
        context.codeBuffer << "pass";
        context.nextLine(true);
    }
    for(auto it = statements->begin(); it != statements->end(); it++) {
        context.indent(true);
        (*it)->codeGenerator(context);
        context.nextLine(true);
    }
    if (context.currentBlock()->isFunction) {
        for(set<string>::iterator it  = context.declaredGlobals().begin(); it != context.declaredGlobals().end(); it++) {
            context.indent(false);
            context.declareGlobal(*it);
            context.nextLine(false);
        }
        context.applyBuf();
    }
}

void OperatorExprNode::codeGenerator(GeneratorContext &context) {
    string res = "";
    switch (op) {
        case EQ:
            res = "==";
            break;
        case NE:
            res = "!=";
            break;
        case GR:
            res = ">";
            break;
        case LW:
            res = "<";
            break;
        case GE:
            res = ">=";
            break;
        case LE:
            res = "<=";
            break;
        case AND:
            res = "and";
            break;
        case OR:
            res = "or";
            break;
        case ADD:
        case SADD:
            res = "+";
            break;
        case SUB:
        case SSUB:
            res = "-";
            break;
        case MUL:
        case SMUL:
            res = "*";
            break;
        case DIV:
        case SDIV:
            res = "/";
            break;
    }
    cout << "test" << endl;
    cout << op << endl;
    cout << res << endl;
    context.codeBuffer << "(";
    left->codeGenerator(context);
    context.codeBuffer << " " << res << " ";
    right->codeGenerator(context);
    context.codeBuffer << ")";
}

void AssignExprNode::codeGenerator(GeneratorContext &context) {
    left->codeGenerator(context);
    context.codeBuffer << " = ";
    right->codeGenerator(context);
}

void FuncExprNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << modify_funcname(funcName->name);
    context.codeBuffer << "(";
    vector<ExprNode*>::iterator it = args->begin();
    if(it != args->end()){
        (*it)->codeGenerator(context);
        for(it = it + 1; it != args->end(); it++) {
            context.codeBuffer << ",";
            (*it)->codeGenerator(context);
        }
    }
    context.codeBuffer << ")";
}

void CastExprNode::codeGenerator(GeneratorContext &context) {
    expr->codeGenerator(context);
}

void IndexExprNode::codeGenerator(GeneratorContext &context) {
    name->codeGenerator(context);
    context.codeBuffer << "[";
    expr->codeGenerator(context);
    context.codeBuffer << "]";
    if(assign != NULL) {
        context.codeBuffer << " = ";
        assign->codeGenerator(context);
    }
}

void ExprStatementNode::codeGenerator(GeneratorContext &context) {
    expr->codeGenerator(context);
}

void VarDecStatementNode::codeGenerator(GeneratorContext &context) {
    if (context.locals().count(name->name) > 0) {
        fprintf(stderr, "duplicate definition %s\n", name->name.c_str());
    }
    else {
        context.locals().insert(name->name);
    }
    name->codeGenerator(context);
    if (!context.funcDeclaring) {
        context.codeBuffer << " = ";
        if (expr != NULL) {
            expr->codeGenerator(context);
        }
        else {
            context.codeBuffer << "None";
        }
    }
}

void ArrayDecStatementNode::codeGenerator(GeneratorContext &context) {
    if (context.locals().count(name->name) > 0) {
        fprintf(stderr, "duplicate definition %s\n", name->name.c_str());
    }
    else {
        context.locals().insert(name->name);
    }
    name->codeGenerator(context);
    if (init->size() == 0) {
        if (type->_type == E_INT) {
            context.codeBuffer << " = [0]*" << size;
        } else {
            context.codeBuffer << " = [None]*" << size;
        }
    }
    else {
        context.codeBuffer << " = [";
        vector<ExprNode*>::iterator it = init->begin();
        if(it != init->end()){
            (*it)->codeGenerator(context);
            for(it = it + 1; it != init->end(); it++) {
                if(isString && (it+1) == init->end()) {
                    break;
                }
                context.codeBuffer << ", ";
                (*it)->codeGenerator(context);
            }
        }
        context.codeBuffer << "]";
    }
}

void ReturnStatementNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << "return ";
    if (hasExpr) {
        expr->codeGenerator(context);
    }
}

void BreakStatementNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << "break";
}

void ContinueStatementNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << "continue";
}

void FuncStatementNode::codeGenerator(GeneratorContext &context) {
    context.funcDeclaring = true;
    context.pushBlock(false, true);
    context.codeOutput << "def ";
    name->codeGenerator(context);
    context.codeOutput << "(";
    int len = args->size();
    if(len > 0){
        int i = 0;
        (*args)[i]->codeGenerator(context);
        for(i+=1; i < len; i++) {
            context.codeOutput << ",";
            (*args)[i]->codeGenerator(context);
        }
    }
    context.codeOutput << "):";
    context.nextLine(false);
    context.funcDeclaring = false;
    block->codeGenerator(context);
    context.popBlock();
}

void IfStatementNode::codeGenerator(GeneratorContext &context) {
    cout << "IfStatement" << endl;
    context.codeBuffer << "if (";
    condExpr->codeGenerator(context);
    context.codeBuffer << "):";
    context.nextLine(true);
    context.pushBlock(true, false);
    trueBlock->codeGenerator(context);
    context.popBlock();
    if(falseBlock->statements->size() == 0) {
        return;
    }
    context.indent(true);
    context.codeBuffer << "else:";
    context.nextLine(true);
    context.pushBlock(true, false);
    falseBlock->codeGenerator(context);
    context.popBlock();
}

void ForStatementNode::codeGenerator(GeneratorContext &context) {
    cout << "ForStatement" << endl;
    initExpr->codeGenerator(context);
    context.nextLine(true);
    context.indent(true);
    context.codeBuffer << "while ";
    condExpr->codeGenerator(context);
    context.codeBuffer << ":";
    context.nextLine(true);
    context.pushBlock(true, false);
    block->statements->push_back(new ExprStatementNode(loopExpr));
    block->codeGenerator(context);
    context.popBlock();
}

void WhileStatementNode::codeGenerator(GeneratorContext &context) {
    context.codeBuffer << "while ";
    whileExpr->codeGenerator(context);
    context.codeBuffer << ":";
    context.nextLine(true);
    context.pushBlock(true, false);
    block->codeGenerator(context);
    context.popBlock();
}