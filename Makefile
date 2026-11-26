all:
	bison -d -v parser.y
	flex lexer.l
	gcc -include ctype.h lex.yy.c parser.tab.c ast.c -o pli

test: all
	./pli valid_test.pli

clean:
	rm -f pli lex.yy.c parser.tab.c parser.tab.h parser.output

.PHONY: all test clean
