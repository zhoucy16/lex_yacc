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

class OperatorExprNode: public ExprNode {
public:
  int op;
  ExprNode *left, *right;

public:
  OperatorExprNode(ExprNode *left, int op, ExprNode *right): left(left), right(right) {}
  virtual void codeGenerator(GeneratorContext&);
};

#endif CODEGENERATOR_H