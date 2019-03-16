#include <stdio.h>
#include <stdlib.h>

#define leftChild(i) (2*i + 1)
#define rightChild(i) (2*i + 2)
#define parent(i) ((i - 1) / 2) 

typedef struct heap{
    int maxSize;
    int* a;
    int end;
} Heap;

void swap(Heap* h, int i1, int i2){
    int temp = h->a[i1];
    h->a[i1] = h->a[i2];
    h->a[i2] = temp;
}

Heap* initHeap(int maxSize){
    Heap* h = malloc(sizeof(Heap));
    if(h != NULL){
        h->a = malloc(maxSize * sizeof(int));
        if(h->a != NULL){
            h->maxSize = maxSize;
            h->end = -1;
            return h;
        }
        else
            free(h);
    }
    else
        return NULL;
}

int reheapUp(Heap* h, int idx){
    if(h == NULL || idx == 0)
        return 0;
    if(h->a[parent(idx)] > h->a[idx])
        swap(h, idx, parent(idx));
    reheapUp(h, parent(idx));
    return 1;
}



int insert(Heap* h, int key){
    if(h == NULL || h->end == h->maxSize - 1)
        return 0;
    
}