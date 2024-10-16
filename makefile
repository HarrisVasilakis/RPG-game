prog: main.cpp Battle.cpp grid.cpp item.cpp Living.cpp Monster.cpp Spells.cpp
	g++ -o prog main.cpp Battle.cpp grid.cpp item.cpp Living.cpp Monster.cpp Spells.cpp -I.
clear:
	rm prog main.o Battle.o grid.o item.o Living.o Monster.o Spells.o
#will work for main.cpp
