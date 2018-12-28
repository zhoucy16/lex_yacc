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
        cout<<"File opening failed\n"<<endl;        
    }
    if(yyparse()){
        cout<<"error"<<endl;
    }
    GeneratorContext context;
    cout << "Generating Python code" << endl;
    cout << "----------------------" << endl;
    context.codeGenerator(*root);
    cout << "----------------------" << endl;
    cout << "Finished" << endl;
    char *outputFilename = "output.py";
    ofstream outfile;
    outfile.open(outputFilename, ios::out);
    context.outputCode(outfile);
    outfile.close();

    fclose(yyin);
    return 0;
}