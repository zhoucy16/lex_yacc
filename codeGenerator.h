#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

enum E_TYPE {
  E_UNKNOWN = -1,
  E_VOID = 0,
  E_CHAR,
  E_DOUBLE,
  E_INT,
  E_PTR,
  E_FUNC,
};

class BaseGeneratorBlock {
public:
  BaseGeneratorBlock();
  set<string> locals;
  set<string> declared_globals;
  bool isFunction;
};

class BlockExprNode;

class GeneratorContext {
public:
  stack<BaseGeneratorBlock *> blocks;
  set<string> globalVariables;
  stringstream code;
  stringstream code_buf;
  int indent_num;
  bool funcDeclaring;

public:
  GeneratorContext();
  ~GeneratorContext();
  void codeGenerator(BlockExprNode &root);
  void outputCode(ostream &out);
  void clearBuf();
  void applyBuf();
  set<string>& locals();
  set<string>& declared_globals();
  set<string>& globals();
  void declareGlobal(string name);
  BaseGeneratorBlock *currentBlock();
  void pushBlock();
  void popBlock();
  void indent();
  void nextLine();
};

class ASTNode {
public:
  ASTNode() {};
  virtual ~ASTNode(){};
  virtual void codeGenerator(GeneratorContext&) = 0;
};

class ExprNode: public ASTNode {
public:
  E_TYPE _type;
};

class StatementNode: public ASTNode {

};

class IntExprNode: public ExprNode {
public:
  long long val;

public:
  IntExprNode(long long val): val(val) {
    _type = E_INT;
  }
  virtual void codeGenerator(GeneratorContext&);
};

class CharExprNode: public ExprNode {
public:
  char val;

public:
  CharExprNode(char val): val(val) {
    _type = E_CHAR;
  }
  virtual void codeGenerator(GeneratorContext&);
};

class VariableExprNode: public ExprNode {
public:
  string name;

public:
  VariableExprNode(const string &name, E_TYPE type = E_UNKNOWN): name(name) {
    _type = type;
  }
  virtual void codeGenerator(GeneratorContext&);
};

class DoubleExprNode: public ExprNode {
  double val;
public:
  DoubleExprNode(double val): val(val){
    _type = E_DOUBLE;
  }
  virtual void codeGenerator(GeneratorContext&);
};


class OperatorExprNode: public ExprNode {
public:
  int op;
  ExprNode *left, *right;

public:
  OperatorExprNode(ExprNode *left, int op, ExprNode *right): left(left), right(right) {}
  virtual void codeGenerator(GeneratorContext&);
};

class BlockExprNode: public ExprNode {
public:
  vector<StatementNode*> *statements;

public:
  BlockExprNode(): statements(new vector<StatementNode*>()) {}
  virtual void codeGenerator(GeneratorContext&);
};

class ExprStatementNode: public StatementNode {
public:
  ExprNode *expression;

public:
  ExprStatementNode(ExprNode *expression): expression(expression) {}
  virtual void codeGenerator(GeneratorContext&);
};

class VarDecStatementNode: public StatementNode {
public:
  VariableExprNode *type;
  VariableExprNode *name;
  ExprNode *expr;

public:
  VarDecStatementNode(VariableExprNode *type, VariableExprNode *name, ExprNode *expr = NULL):
  type(type), name(name), expr(expr) {}
  virtual void codeGenerator(GeneratorContext&);
};

class FuncDecStatementNode: public StatementNode {
public:
  VariableExprNode *type;
  VariableExprNode *name;
  vector<VarDecStatementNode*> *args;
  BlockExprNode *block;

public:
  FuncDecStatementNode(VariableExprNode *type, VariableExprNode *name, 
    vector<VarDecStatementNode*> *args, BlockExprNode *block): 
    type(type), name(name), args(args), block(block) {}
  virtual void codeGenerator(GeneratorContext&);
};

class ReturnStatementNode: public StatementNode {
public:
  ExprNode *expr;

public:
  ReturnStatementNode(ExprNode *expr): expr(expr) {}
  virtual void codeGenerator(GeneratorContext&);
};

class ArrayDecStatementNode: public StatementNode {
public:
  VariableExprNode *type;
  VariableExprNode *name;
  vector<ExprNode*> *init;
  long long size;
  bool isString;

public:
  ArrayDecStatementNode(VariableExprNode *type, VariableExprNode *name, long long size): 
    type(type), name(name), init(new vector<ExprNode*>()), size(size), isString(false) {}
  ArrayDecStatementNode(VariableExprNode *type, VariableExprNode *name, vector<ExprNode*> *init): 
    type(type), name(name), init(init), size(init->size()), isString(false) {}
  ArrayDecStatementNode(VariableExprNode *type, VariableExprNode *name, const string &str):
    type(type), name(name), init(new vector<ExprNode*>()), isString(true) {
      int len=str.length();
      for(int i=0; i<len; i++){
        init->push_back((ExprNode*)(new CharExprNode(str[i])));
      }
      //init->push_back((ExprNode*))
      // !!!!!!!!!!!!!!!!!!!!
      size = init->size();
    }
  virtual void codeGenerator(GeneratorContext&);
};

class ForStatementNode: public StatementNode {
public:
  ExprNode *initExpr;
  ExprNode *condExpr;
  ExprNode *loopExpr;
  BlockExprNode *block;
public:
  ForStatementNode(ExprNode *initExpr, ExprNode *condExpr, ExprNode *loopExpr, BlockExprNode *block):
    initExpr(initExpr), condExpr(condExpr), loopExpr(loopExpr), block(block) {}
  virtual void codeGenerator(GeneratorContext&);
};

class WhileStatementNode: public StatementNode{
public:
  ExprNode *whileExpr;
  BlockExprNode *block;
public:
  WhileStatementNode(ExprNode *whileExpr, BlockExprNode *block):
    whileExpr(whileExpr),block(block){}
  virtual void codeGenerator(GeneratorContext&);
};

class AssignExprNode: public ExprNode{
public:
  VariableExprNode *left;
  ExprNode *right;
public:
  AssignExprNode(VariableExprNode *left, ExprNode *right):
    left(left),right(right) {}
  virtual void codeGenerator(GeneratorContext&);
};

class FuncExprNode: public ExprNode {
public:
  VariableExprNode *funcName;
  vector<ExprNode*> *args;
public:
  FuncExprNode(VariableExprNode *funcName):
    funcName(funcName), args(new vector<ExprNode*>()) {}
  FuncExprNode(VariableExprNode *funcName, vector<ExprNode*> *args):
    funcName(funcName), args(args) {}
  virtual void codeGenerator(GeneratorContext&);
};

class IndexExprNode: public ExprNode {
public:
  VariableExprNode *name;
  ExprNode *expr;
  ExprNode *assign;
public:
  IndexExprNode(VariableExprNode *name, ExprNode *expr): 
    name(name),expr(expr),assign(NULL) {}
  IndexExprNode(VariableExprNode *name, ExprNode *expr, ExprNode *assign):
    name(name),expr(expr),assign(assign) {}
  virtual void codeGenerator(GeneratorContext&);
};

class CastExprNode: public ExprNode {
public:
  VariableExprNode *type;
  ExprNode *expr;
public:
  CastExprNode(VariableExprNode *type, ExprNode *expr):
    type(type), expr(expr) {}
  virtual void codeGenerator(GeneratorContext&);  
};

class IfStatementNode: public StatementNode {
public:
  ExprNode *condExpr;
  BlockExprNode *trueBlock;
  BlockExprNode *falseBlock;
public:
  IfStatementNode(ExprNode *condExpr, BlockExprNode *trueBlock):
    condExpr(condExpr), trueBlock(trueBlock), falseBlock(new BlockExprNode()) {}
  IfStatementNode(ExprNode *condExpr, BlockExprNode *trueBlock, BlockExprNode *falseBlock):
    condExpr(condExpr), trueBlock(trueBlock), falseBlock(falseBlock) {}
  virtual void codeGenerator(GeneratorContext&);
};



#endif CODEGENERATOR_H