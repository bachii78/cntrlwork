all : main3.o sort.o
	g++ main.o sort.o

main.o : main3.c
	g++ -c main3.c -std=c++17
sorts.o         :       sort.c
	g++ -c sort.c
clean :
	rm -rf *.o a.out

