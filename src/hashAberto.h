#ifndef HASHABERTO_H
#define HASHABERTO_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define hash(v, S) (v % S)
#define hash2(v, R) (R - (v%R))

typedef struct HashOpen HashOpen;

struct HashOpen{
    int *H;
    int S;
    int R;
    int colision;
};

void CreateHashOpen(HashOpen *h, int size);
void InsertHashOpen(HashOpen *h, int value);
void RemoveHashOpen(HashOpen *h, int value);
bool SearchHashOpen(HashOpen *h, int value);
void PrintHashOpen(HashOpen *h);
int FindNextPrime(int number);
int FindPreviousPrime(int number);
bool IsPrime(unsigned int number);

#endif