#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node* next;
    struct node* prev;
    int key;
}Node;

Node* initNode(Node* next, Node* prev, int key){
    Node* n = malloc(sizeof(Node));
    n->next = next;
    n->prev = prev;
    n->key = key;
    return n;
}

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LL;

void addFront(LL* l, int key){
    Node* ptr;
    ptr = initNode(l->head, NULL, key);
    l->head = ptr;
}

void removeFront(LL* l){
    Node* ptr = l->head;
    if(l->size > 1){
        l->head = l->head->next;
        l->head->prev == NULL;
        free(ptr);
    }
    else if(l->size == 1){
        free(ptr);
    }
    else
        return;
}

void removeEnd(LL* l){
    Node* ptr = l->tail;
    if(l->size > 1){
        l->
    }
}

int find(LL* l, int value){
    if(l->head != NULL){
        Node* ptr = malloc(sizeof(Node));
        while(ptr != NULL){
            if(ptr->key = value)
                return 1;
            ptr = ptr->next;
        }
    return 0;
    }
}
typedef struct HashTable {
    LL** a;
    int collisions;
    int size;
} Hash;

Hash* initHash(int size){
    Hash* h = malloc(sizeof(Hash));
    h->size = size;
    h->collisions = 0;
    h->a = malloc(size * sizeof(LL));
}

int hashCode(int key){
    int s = key*65599l;
    return s;
}

int index(int key, Hash* h){
    int idx = hashCode(key) % (h->size);
    return idx;
}

int isEmpty(LL* l){
    if (l == NULL || l->head == NULL)
        return 1;
    else
        return 0;
}

float loadFactor(Hash* h){
    int count = 0;
    for(int i = 0; i < h->size; i++){
        if(isEmpty(h->a[i]))
            count += 1;
    }

    return count/(h->size);
}

int insert(Hash* h, int key){
    int idx = index(key, h);
    if(!isEmpty(h->a[idx]))
        h->collisions++;
    addFront(h->a, key);
}

int findInTable(Hash* h, int key){
    int idx = index(key, h);
    if(find(h->a[idx], key)){
        printf("Found at %d", idx);
        return idx;
    }
    else
        return 0;
}

int removeKey(Hash* h, int key){
    int idx;
    Node* ptr;
    if(idx = findInTable(h, key))
        ptr = h->a[idx];
        while(ptr != NULL){
            if(ptr->key = key){
                printf("Removed %d from index %d", key, idx);

            else ptr = ptr->next;
        }
}