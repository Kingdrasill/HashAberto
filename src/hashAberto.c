#include "hashAberto.h"

void CreateHashOpen(HashOpen *h, int size) {
    size = size*2;
    h->H = (int*)malloc(size * sizeof(int));
    h->S = FindNextPrime(size);
    h->R = FindPreviousPrime(h->S);
    h->colision = 0;
    
    for(int i=0; i<h->S; i++)
        h->H[i] = -1;
}

void InsertHashOpen(HashOpen *h, int value) {
    int key = hash(value, h->S);
    int offset = hash2(value, h->R);
    bool frtItr = true;

    while(h->H[key] != -1) {
        if(h->H[key] == -2)
            break;
        key = (key+offset) % h->S;

        if(!frtItr)
            h->colision++;

        frtItr = false;
    }

    h->H[key] = value;
}

void RemoveHashOpen(HashOpen *h, int value) {
    if(!SearchHashOpen(h, value))
        return;
    
    int key = hash(value, h->S), offset = hash2(value, h->R);

    while(h->H[key] != -1) {
        if(h->H[key] == value) {
            h->H[key] = -2;
            return;
        } else {
            key = (key+offset)%h->S;
        }
    }
}

bool SearchHashOpen(HashOpen *h, int value) {
    int key = hash(value, h->S), offset = hash2(value, h->R);
    int initialPos = key;
    bool fstItr = true;

    while(true) {
        if(h->H[key] == -1)
            break;
        else if(h->H[key] == value)
            return true;
        else if(key == initialPos && !fstItr)
            return false;
        else
            key = (key+offset)%h->S;
        
        fstItr = false;
    }

    return false;
}

void PrintHashOpen(HashOpen *h) {
    for(int i=0; i<h->S; i++) {
        printf("%d, ", h->H[i]);
    }
    printf("\n");
}

int FindNextPrime(int number) {
    int next = number;
    bool found = false;

    while (!found)
    {
        next++;
        if(IsPrime(next))
            found = true;
    }

    return next;    
}

int FindPreviousPrime(int number) {
    for(int i = number - 1; i >= 2; i--) {
        bool prime = true;
        for(int j = 2; j <= sqrt(i); j++ ) {
            if(i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime == true) {
            return i;
        }
    }
    return 2;
}

bool IsPrime(unsigned int number) {
    if (number <= 1) 
        return false; // zero and one are not prime
    for (unsigned int i=2; i*i<=number; i++) {
        if (number % i == 0) 
            return false;
    }
    return true;
}