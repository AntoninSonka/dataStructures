#include "structures.h"

int main(int argc, char *argv[]){
    
    printf("Hello, World\n");

    lList* base = initList();
    printList(base);
    printf("size: %d\n", (int)base->size);
    pushBackList(base, 10);
    printList(base);
    printf("size: %d\n", (int)base->size);
    pushBackList(base, 5);
    printList(base);
    printf("size: %d\n", (int)base->size);
    pushBackList(base, 9);
    printList(base);
    printf("size: %d\n", (int)base->size);
    insertList(base, 4, 3);
    printList(base);
    printf("size: %d\n", (int)base->size);
    struct nodeList* nodeA = accessNodeByValueList(base, 9);
    if(nodeA  != NULL){
        printf("thisNode: %d\n", nodeA->val);
    }
    struct nodeList* nodeB = accessNodeByIndexList(base, 3);
    if(nodeB  != NULL){
        printf("thisNodeA: %d\n", nodeB->val);
    }

    printf("index: %d\n", getIndexList(base, 9));

    removeByIndexList(base, getIndexList(base, 5));   
    printList(base);
    printf("size: %d\n", (int)base->size);
    removeByValueList(base, 4);
    printList(base);
    printf("size: %d\n", (int)base->size);
    removeByIndexList(base, 0);   
    printList(base);
    printf("size: %d\n", (int)base->size);
    removeByIndexList(base, 0);   
    printList(base);
    printf("size: %d\n", (int)base->size);
    removeByIndexList(base, 0);   
    printList(base);
    printf("size: %d\n", (int)base->size);
    freeList(base);

    return 0;
}
