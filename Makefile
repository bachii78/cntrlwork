all : main3.o sorts.o
	g++ main.o sorts.o

main.o : main3.c
	g++ -c main3.c -std=c++17
sorts.o         :       sorts.c
	g++ -c sorts.c
clean :
	rm -rf *.o a.out

