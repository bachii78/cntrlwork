all : main3.o sort.o
	g++ main3.o sort.o

main.o : main3.cpp
	g++ -c main3.cpp 
sort.o         :       sort.cpp
	g++ -c sort.cpp
clean :
	rm -rf *.o a.out

