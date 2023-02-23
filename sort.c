#include "sort.hpp"

void showEl(const int* ar, int size, char delimited = ' ') {
	for (int i = 0; i < size; i++) {
		std::cout << ar[i] << delimited;
	}
	std::cout << std::endl;
}

void setRandom(int *ar, int size, int min, int max){
        srand(time(nullptr));
        for (int i = 0; i < size; i++){
                ar[i] = rand()%(max - min + 1) + min;
        }
}

void swap(int&a, int&b){
    int temp = a;
    a = b;
    b = temp;

}

void SelectionSort(int* arr, int size){
    for (int i = 0; i < size - 1; i++){
        int min_index = i;
        for (int j = i + 1; j < size; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            swap(arr[i], arr[min_index]);
        }
    }
}

void insertionSort(int* ar, int size){
    for(int i = 0; i < size - 1; i++){
            int j = i;
            for(j; j >= 0 && ar[j+1] < ar[j]; j--){
                swap(ar[j + 1], ar[j]);
            }

    }
}

static void merge(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] <= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
//            left++;
//            indexTemp++;
        }
        while(ar[left] > ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}

void mergeSort(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergeSort(&ar[0], size >> 1);
    mergeSort(&ar[size >> 1], size - (size >> 1));

    merge(ar, size, size >> 1);
}

void quickSort(int* ar, int size) {
	int left = 0;
	int right = size - 1;
	int pivot = ar[size >> 1];

	while(left <= right) {
		while(ar[left] < pivot) {
			left++;
		}

		while (ar[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(ar[right], ar[left]);
			right--;
			left++;
		}
	}
	if (right > 0) {
		quickSort(&ar[0], right + 1);
	}

	if (left < size) {
		quickSort(&ar[left], size - left);
	}
}

void countSort(int* ar, int size){
	int countAr[1000];
	for(int i = 0; i < 1000; i++){
		countAr[i] = 0;
	}
	for (int i = 0; i < size; i++){
 		countAr[ar[i]]++;
	}
	int index = 0;
	for(int i = 0; i < 1000; i++){
		if(countAr[i] != 0){
			int j = countAr[i];
			for(j,index; j > 0; index++, j--){
				ar[index] = i;
			}
		}
	}

}

void bubbleSort(int* ar, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(ar[j] > ar[i]){
				swap(ar[i], ar[j]);
			}
		}
	}
}
