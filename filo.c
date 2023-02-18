#include "filo.h"

void fillRandom(filo* filotest){
    srand(time(nullptr));
    for(int i = 0; i < filotest->size; i++){
        filotest->ar[i] = rand() % 100;
    }
}
void showMass(filo* filotest){
    for(int i = 0; i < filotest->size; i++){
        std::cout << filotest->ar[i] << '\t';
    }
    std::cout << std::endl;
}
int getFromEnd(filo* filotest, char* element){
    if(!filotest->datalen){
        return -1;
    }
    *element = filotest->ar[--filotest->datalen];
    return 0;
 }

int putToEnd(filo* filotest, char element){
    if(filotest->datalen >= filotest->size){
        return 1;
    }
    filotest->ar[filotest->datalen++] = element;
    return 0;
}

void deinit(filo* filotest){
    delete [] filotest->ar;
}

void initBuffer(filo* filotest, int _size){
    filotest->size = _size;
    filotest->datalen = 0;
    filotest->ar = new char[_size];
}

void flush(filo* filotest){
    filotest->datalen = 0;
}

bool checkBr(filo* filotest){
	if(filotest->size != 0){
		return false;
	}
	return true;
}

