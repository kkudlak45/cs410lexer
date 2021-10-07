cp test.c test.lex;
flex test.lex;
gcc lex.yy.c;
