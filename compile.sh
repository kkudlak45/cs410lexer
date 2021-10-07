cp main.c main.lex;
flex main.lex;
gcc lex.yy.c;
