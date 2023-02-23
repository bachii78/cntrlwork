#include <iostream>
#include <time.h>
#include "sort.hpp"
#include <chrono>

int flagBubble = 0;
int flagInsert = 0;
int flagSelect = 0;
int flagQuick = 0;
int flagMerge = 0;
int flagCount = 0;

int TimeBubbleSort(int* ar, int size, int&flag){
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	bubbleSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;

}

int  TimeInsertionSort(int* ar, int size,int& flag){
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	insertionSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;
}

int TimeQuickSort(int* ar, int size,int& flag){
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	quickSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;
}

int TimeMergeSort(int* ar, int size, int&flag){
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	mergeSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;
}

int TimeCountSort(int* ar, int size, int&flag){
	setRandom(ar, size, 0, 999);
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	countSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;
}

int TimeSelectionSort(int* ar, int size, int&flag){
	setRandom(ar, size, 0, 999);
	if(flag == 0){
		setRandom(ar, size, 0, 999);
        	std::chrono::time_point<std::chrono::high_resolution_clock> start;
        	start = std::chrono::high_resolution_clock::now();
        	SelectionSort(ar, size);
        	std::chrono::time_point<std::chrono::high_resolution_clock> end;
		end = std::chrono::high_resolution_clock::now();
        	std::chrono::duration<double> diff = end - start;
        	std::cout<<diff.count() << "\t";
		double temp = diff.count();
		if(temp > 60){
			flag = 1;
		}
	}
	else{
		std::cout<<'\t'<<'\t';
	}
	return 0;
}

void Time(int start, int limit, int step){
	for(int i = start; i <= limit; i += step){
	std::cout << i << '\t';
	int* ar;
	ar = new int[start + i];	
	TimeBubbleSort(ar, start + i, flagBubble);
	TimeMergeSort(ar, start + i, flagMerge);
	TimeInsertionSort(ar, start + i, flagInsert);
	TimeSelectionSort(ar, start + i, flagSelect);
	TimeQuickSort(ar, start + i, flagQuick);
	TimeCountSort(ar, start + i, flagCount);
	std::cout << '\n';
	delete [] ar;
	}

}

int main(){

//	std::cout<<"размер"<< '\t'<<"пузырьковая"<<'\t'<<"слиянием"<<'\t'<<"вставками"<<'\t'<<"выбором"<<'\t'<<'\t'<<"бысрая"<<'\t'<<'\t'<< "подсчетом"<<'\n';
	Time(100, 500, 100);
	Time(500, 1000, 250);
	Time(1000, 10000, 1000);
	Time(10000, 100000, 5000);
	Time(100000, 200000, 10000);
	Time(200000, 1000000, 100000);
	Time(1000000, 10000000, 1000000);
    return 0;
}
