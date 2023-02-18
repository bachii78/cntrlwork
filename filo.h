#ifndef FILO_H
#define FILO_H
#include <iostream>
#include <time.h>

struct filo{
    int size;
    char* ar;
    int datalen; //позиция первого пустого элемента
};
void showMass(filo*);

void fillRandom(filo*);

int putToEnd(filo*, char);

int getFromEnd(filo*, char*);

void deinit(filo*);

void flush(filo*);

void initBuffer(filo*, int);

bool checkBr(filo*);

#endif // FILO_H
