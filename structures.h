#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct nodeList {
    int val;
    struct nodeList* next;
};

typedef struct{

    struct nodeList* head;
    size_t size;

}lList;

void pushBackList(lList* base, int val);
lList* initList();
void freeList(lList* base);
void printList(lList* base);
struct nodeList* accessNodeByValueList(lList* base, int val);
struct nodeList* accessNodeByIndexList(lList* base, int index);
int insertList(lList* base, int val, int index);
int getIndexList(lList* base, int val);
int removeByIndexList(lList* base, int index);
int removeByValueList(lList* base, int val);

#endif //!STRUCTURES_H
