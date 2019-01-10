#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "codeGenerator.h"

using namespace std;

extern FILE* yyin;
extern BlockExprNode* root;
extern int yyparse();

int main(int argc, char **argv) {
    char *filename;
    if (argc == 2)
        filename = argv[1];
    else
        return 0;
    yyin = fopen(filename,"r");
    if(!yyin){
        cout<<"Open file failed\n"<<endl;        
    }
    if(yyparse()){
        cout<<"Error"<<endl;
    }
    GeneratorContext context;
    cout << "Compiling  to Python" << endl;
    cout << "----------------------" << endl;
    context.codeGenerator(*root);
    cout << "----------------------" << endl;
    cout << "Finish compile" << endl;
    string inputFileName = filename;
    inputFileName.pop_back();
    inputFileName.pop_back();
    string outputFilename = inputFileName + ".py";
    ofstream outfile;
    outfile.open(outputFilename, ios::out);
    context.outputCode(outfile);
    outfile.close();

    fclose(yyin);
    return 0;
}