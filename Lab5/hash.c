// HASH.C
// Program for use with ELEC278 Lab 5 Part 2.
//
// History:
// 161106	HF	First release
// 171102	DA	Minor tweaks


#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"
#include <time.h>
#include <math.h>

typedef struct HashTable {
	LinkedList** a;
	int size;
	int collisions;
} HashTable;


HashTable* initHashTable(int s)
{
	HashTable* h = malloc(sizeof(HashTable));
	int		i;
	h->size = s;
	h->a = malloc(sizeof(LinkedList) * s);
	for(i=0;i<s;i++)
		h->a[i]= init();
	h->collisions = 0;
	return h;
}//initHashTable()


long h(char* x)
// This function computes a hash code for a given string.  Note that hash
// code is unbounded - it needs to be reduced modulo the size of the array
// used to store the data. (You will see another function hash() below that
// completes the index calculation.)
{
	long	sum=0;
	//#########################COMPLETE THIS FUNCTION##########################
	// Requirements given in lab instructions.
	// ---<SNIP>---
    int i;
    int n = strlen(x);
    for(i = 0; i < n; i++)
    {
	sum += x[i]*pow(31, n-1-i);
    }
	// ---<SNIP>---
	return sum;
}//h()


double loadFactor(HashTable* ht)
{
	double nonempty = 0;
	int i;
	// count number of non-empty hash table slots
	for(i=0; i<ht->size; i++)	{
		if (isEmpty(ht->a[i])==0)	nonempty++;
		}
	return nonempty/ht->size*100;
}//loadFactor()


int hash(char* x, int size)
// Index calculation. Function h() computes general hash for the string;
// this function turns the hash into a valid index, given the size of the
// array.
{
	return h(x) % size;
}


void insert(HashTable *ht, char* x)
{
	//#########################COMPLETE THIS FUNCTION##########################
	// ---<SNIP>---
    int index = hash(x, ht->size); //find correct index for new string
    if(isEmpty(ht->a[index])) //check if linked list at that index is empty
        ht->collisions++;
    addFront(ht->a[index], x);

	// ---<SNIP>---
}//insert()


int findInTable(HashTable *ht, char* x)
{
	//#########################COMPLETE THIS FUNCTION##########################
	// ---<SNIP>---
    int index = hash(x, ht->size);
    if(find(ht->a[index], x))
    {
        printf("Found %s at index %d\n", x, index);
        return index;
    }
    else
    {
        printf("Could not find %s", x);
        return -1;
    }
	// ---<SNIP>---	
}


void printTable(HashTable *ht)
{
	int i;
	printf("----------\n");
	for (i = 0; i < ht->size; i++)	{
		printf("%d --> ", i);
		print(ht->a[i]);
		}
	printf("# of Collisions=%d\n", ht->collisions);
	printf("Load Factor %%=%.2f\n----------\n", loadFactor(ht));
}

int remove_key(HashTable *h, char* x)
{
	int index = findInTable(h, x);
	if(index == -1)
		{
			printf("This key isn't in the table");
			return 0;
		}
	else
		{
			Node* ptr = h->a[index]->head;
			printf("Test1");
			while(ptr != NULL)
			{
				if(strcmp(ptr->value, x) == 0) //check if matches entry
					{
						if(ptr->next == NULL) //checks if end of linked list
							removeEnd(h->a[index]);
						else if(ptr->prev == NULL) //checks if beginning of linked list
							removeFront(h->a[index]);
						else 
						{
							ptr->prev->next = ptr->next;
							h->a[index]->size--;
						}
						free(ptr);
						break;
					}
				ptr = ptr->next;
			}
			printf("Test2");
			return 1;

		}
}


int main() {
	//FILE *fp;
	//fp = fopen("words.txt","w+");
	int i=0;
	HashTable* h = initHashTable(101);


	// Generate a set of random strings (given the way this works, everyone
	// gets the same set of random strings!) insert each into the hash table
	// and then print the table.
	for(i=0;i<100;i++){
		int x = rand()%5+1;
		char *p = malloc(sizeof(char)*x);
		int j=0;
		for(j=0;j<x;j++)
			p[j] = rand()%26 + 97;
		p[j]='\0';
		insert(h,p);
	}
	printTable(h);
	remove_key(h, "fnuxx");
	printf("Test3");
	remove_key(h, "jlf");
	printf("Test4");
	printTable(h);
	return 0;
}
