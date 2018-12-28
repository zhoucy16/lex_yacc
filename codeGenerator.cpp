#include "codeGenerator.h"
#include "AST_parser.hpp"

#define INDENT 4

extern int yyparse();
extern BlockExprNode* root;

string modify_funcname(string name) {
    if(name == "strlen") {
        return "len";
    }
    else if (name == "isdigit") {
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
    code << "# -*- coding:utf-8" << endl;
    root.codeGenerator(*this);
    code << "\nif __name__ == \"__main__\":\n    main()\n";
}

void GeneratorContext::outputCode(ostream& out) {
    out << code.str();
}

void GeneratorContext::clearBuf() {
    code_buf.str("");
}

void GeneratorContext::applyBuf() {
    code << code_buf.str();
    clearBuf();
}

set<string>& GeneratorContext::locals() {
    return blocks.top()->locals;
}

set<string>& GeneratorContext::declared_globals() {
    return blocks.top()->declared_globals;
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
        block->declared_globals = blocks.top()->declared_globals;
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
            code_buf << ' ';
        }
        else {
            code << ' ';
        }
    }
}

void GeneratorContext::declareGlobal(string name) {
    code << "global " << name;
}

void GeneratorContext::nextLine(bool buf) {
    if(buf) {
        code_buf << '\n';
    }
    else {
        code << '\n';
    }
}

void VariableExprNode::codeGenerator(GeneratorContext &context){
    if(context.funcDeclaring) {
        if(context.globals().count(name) > 0) {
            fprintf(stderr, "Duplicate naming %s\n", name.c_str());
        }
        else {
            context.locals().insert(name);
            context.code << name;
        }
    }
    else {
        if(context.locals().count(name) > 0) {
            context.code_buf << name;
        }
        else if (context.globals().count(name) > 0){
            if (context.declared_globals().count(name) > 0) {
                context.code_buf << name;
            }
            else {
                context.declared_globals().insert(name);
                context.code_buf << name;
            }
        }
        else {
            fprintf(stderr, "Undeclared symbol %s\n", name.c_str());
        }
    }
}

void CharExprNode::codeGenerator(GeneratorContext &context) {
    if (val == '\'' || val == '\\') {
        context.code_buf << "\'\\" << val << "\'";
    }
    else {
        context.code_buf << "\'" << val << "\'";
    }
}

void IntExprNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << val;
}

void DoubleExprNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << val;
}

void BlockExprNode::codeGenerator(GeneratorContext &context) {
    for(auto it = statements->begin(); it != statements->end(); it++) {
        context.indent(true);
        (*it)->codeGenerator(context);
        context.nextLine(true);
    }
    if (context.currentBlock()->isFunction) {
        for(auto it  = context.declared_globals().begin(); it != context.declared_globals().end(); it++) {
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
    context.code_buf << "(";
    left->codeGenerator(context);
    context.code_buf << " " << res << " ";
    right->codeGenerator(context);
    context.code_buf << ")";
}

void AssignExprNode::codeGenerator(GeneratorContext &context) {
    left->codeGenerator(context);
    context.code_buf << " = ";
    right->codeGenerator(context);
}

void FuncExprNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << modify_funcname(funcName->name);
    context.code_buf << "(";
    vector<ExprNode*>::iterator it = args->begin();
    if(it != args->end()){
        (*it)->codeGenerator(context);
        for(it = it + 1; it != args->end(); it++) {
            context.code_buf << ",";
            (*it)->codeGenerator(context);
        }
    }
    context.code_buf << ")";
}

void CastExprNode::codeGenerator(GeneratorContext &context) {
    expr->codeGenerator(context);
}

void IndexExprNode::codeGenerator(GeneratorContext &context) {
    name->codeGenerator(context);
    context.code_buf << "[";
    expr->codeGenerator(context);
    context.code_buf << "]";
    if(assign != NULL) {
        context.code_buf << " = ";
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
        context.code_buf << " = ";
        if (expr != NULL) {
            expr->codeGenerator(context);
        }
        else {
            context.code_buf << "None";
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
        context.code_buf << " = [None]*" << size;
    }
    else {
        context.code_buf << " = [";
        vector<ExprNode*>::iterator it = init->begin();
        if(it != init->end()){
            (*it)->codeGenerator(context);
            for(it = it + 1; it != init->end(); it++) {
                if(isString && (it+1) == init->end()) {
                    break;
                }
                context.code_buf << ", ";
                (*it)->codeGenerator(context);
            }
        }
        context.code_buf << "]";
    }
}

void ReturnStatementNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << "return ";
    expr->codeGenerator(context);
}

void FuncDecStatementNode::codeGenerator(GeneratorContext &context) {
    context.funcDeclaring = true;
    context.pushBlock(false, true);
    context.code << "def ";
    name->codeGenerator(context);
    context.code << "(";
    int len = args->size();
    if(len > 0){
        int i = 0;
        (*args)[i]->codeGenerator(context);
        for(i+=1; i < len; i++) {
            context.code_buf << ",";
            (*args)[i]->codeGenerator(context);
        }
    }
    context.code << "):";
    context.nextLine(false);
    context.funcDeclaring = false;
    block->codeGenerator(context);
    context.popBlock();
}

void IfStatementNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << "if (";
    condExpr->codeGenerator(context);
    context.code_buf << "):";
    context.nextLine(true);
    context.pushBlock(true, false);
    trueBlock->codeGenerator(context);
    context.popBlock();
    if(falseBlock->statements->size() == 0) {
        return;
    }
    context.indent(true);
    context.code_buf << "else:";
    context.pushBlock(true, false);
    trueBlock->codeGenerator(context);
    context.popBlock();
}

void ForStatementNode::codeGenerator(GeneratorContext &context) {
    initExpr->codeGenerator(context);
    context.nextLine(true);
    context.indent(true);
    context.code_buf << "while ";
    condExpr->codeGenerator(context);
    context.code_buf << ":";
    context.nextLine(true);
    context.pushBlock(true, false);
    block->statements->push_back(new ExprStatementNode(loopExpr));
    block->codeGenerator(context);
    context.popBlock();
}

void WhileStatementNode::codeGenerator(GeneratorContext &context) {
    context.code_buf << "while";
    whileExpr->codeGenerator(context);
    context.code_buf << ":";
    context.nextLine(true);
    context.pushBlock(true, false);
    block->codeGenerator(context);
    context.popBlock();
}