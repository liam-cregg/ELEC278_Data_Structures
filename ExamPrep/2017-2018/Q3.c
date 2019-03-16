#include <stdio.h>
#include <stdlib.h>


//Part 1
struct stack{
    int tos;
    int* stk;
    int max;
};

struct stack* createStack(int size){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    if(s == NULL)
        return NULL;
    int a[size];
    s->tos = -1;
    s->stk = a;
    s->max = size;
    return s;
}

int isempty(struct stack* s){
    if(s->tos == -1)
        return 1;
    else
        return 0;
}

int isfull(struct stack* s){
    if(s->tos == s->max - 1)
        return 1;
    else
        return 0;
}

int push(struct stack* s, int x){
    if(!isfull(s)){
        s->stk[++(s->tos)] = x;
        return 1;
    }
    else
        return 0;
}

int pop(struct stack* s, int* px){
    if(!isempty(s)){
        *px = s->stk[(s->tos)--];
        return 1;
    }
    else  
        return 0;
}
int main(){
    //Part 2
    struct stack* pstack = createStack(100);
    int temp;

    for(int i = 0; i<100; i++){
        temp = rand() % 10;
        if(temp % 2 == 0)
            temp = -temp;
        push(pstack, temp);
    }

    struct stack* positives = createStack(100);
    struct stack* negatives = createStack(100);
    int p;

    int test = pstack->stk[pstack->tos];

    while(pop(pstack, &p)){
        if (p >= 0)
            push(positives, p);
        else
            push(negatives, p);
    }

    while(pop(negatives, &p)){
        push(pstack, p);
    }

    while(pop(positives, &p)){
        push(pstack, p);
    }

    while(pop(pstack, &p)){
    printf("%d ", p);
    }
}