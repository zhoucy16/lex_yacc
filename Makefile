all: compiler

OBJS = AST_parser.o lexical.o codeGenerator.o main.o

AST_parser.cpp: AST_parser.y
	bison -d -o $@ $^

AST_parser.hpp: AST_parser.cpp

lexical.cpp: lexical.l AST_parser.hpp
	flex -L -o $@ $^

%.o: %.cpp
	g++ -c -std=c++11 -g -o $@ $^

compiler: $(OBJS)
	g++ -o $@ $(OBJS)

clean:
	rm -rf AST_parser.cpp AST_parser.hpp compiler lexical.cpp $(OBJS)