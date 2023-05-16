flex -o lex.cpp 1805063_lex.l
g++ lex.cpp -lfl -o lex.out
./lex.out in.txt
