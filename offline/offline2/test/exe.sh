flex -o lex.cpp pr.l
g++ lex.cpp -lfl -o lex.out
./lex.out input.txt
