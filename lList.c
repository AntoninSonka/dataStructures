#include "structures.h"

void _pushBackList(struct nodeList* head, int val){
    if(head->next == NULL){
        struct nodeList* nextNode = (struct nodeList*) malloc(sizeof(struct nodeList));
        nextNode->next = NULL;
        nextNode->val = val;
        head->next = nextNode;
        return;
    }
    _pushBackList(head->next, val);
}

void pushBackList(lList* base, int val){
    base->size++;
    if(base->head == NULL){
        struct nodeList* nextNode = (struct nodeList*) malloc(sizeof(struct nodeList));
        nextNode->next = NULL;
        nextNode->val = val;
        base->head = nextNode;
        return;
    }
    _pushBackList(base->head, val);
}

lList* initList(){
    lList* base = (lList*) malloc(sizeof(lList));

    base->head = NULL;
    base->size = 0;

    return base;
}

void _freeList(struct nodeList* head){
    if(head->next == NULL){
        free(head);
        return;
    }
    _freeList(head->next);
    free(head);
}

void freeList(lList* base){

    if(base->head != NULL)
        _freeList(base->head);

    free(base);
}

void _printList(struct nodeList* head){
    printf("%d -> ", head->val);
    if(head->next == NULL){
        printf("NULL\n");
        return;
    }
    _printList(head->next);
}

void printList(lList* base){
    if(base->head == NULL){
        printf("NULL\n");
        return;
    }
    _printList(base->head);
}

struct nodeList* _accessNodeByValueList(struct nodeList* head, int val){
    if(head->val == val)
        return head;
    if(head->next == NULL)
        return NULL;
    return _accessNodeByValueList(head->next, val);
}

struct nodeList* accessNodeByValueList(lList* base, int val){
    if(base->head == NULL){
        return NULL;
    }
    return _accessNodeByValueList(base->head, val);
}

struct nodeList* _accessNodeByIndexList(struct nodeList* head, int index, int counter){
    if(counter == index){
        return head;
    }
    if(head->next == NULL){
        return NULL;
    }
    return _accessNodeByIndexList(head->next, index, counter + 1);
}

struct nodeList* accessNodeByIndexList(lList* base, int index){
    if(index > (base->size - 1) || index < 0){
        return NULL;
    }
    return _accessNodeByIndexList(base->head, index, 0);
}

void _insertList(struct nodeList* head, int val, int index, int counter){

    if(counter == index){
        struct nodeList* nextNode = (struct nodeList*) malloc(sizeof(struct nodeList));
        nextNode->val = val;

        if(head->next == NULL){
            nextNode->next = NULL;
            head->next = nextNode;
            return;
        }

        nextNode->next = head->next;
        head->next = nextNode;
        return;
    }

    if(head->next == NULL){
        return;
    }

    _insertList(head->next, val, index, counter + 1);
}

int insertList(lList* base, int val, int index){
    if(index > base->size || index < 0){
        return 1;
    }

    if(index == 0){
        struct nodeList* nextNode = (struct nodeList*) malloc(sizeof(struct nodeList));
        nextNode->val = base->head->val;
        base->head->val = val;
        if(base->head->next == NULL){
            base->head->next = nextNode;
            nextNode->next = NULL;
            return 0;
        }
        nextNode->next = base->head->next;
        base->head->next = nextNode;
        return 0;
    }

    _insertList(base->head, val, index, 1);
    base->size++;
    return 0;
}

int _getIndexList(struct nodeList* head, int val, int index){
    
    if(head->val == val){
        return index;
    }

    if(head->next == NULL){
        return -1;
    }
    return _getIndexList(head->next, val, index + 1);
}

int getIndexList(lList* base, int val){
    return _getIndexList(base->head, val, 0);
}

void _removeByIndexList(struct nodeList* head, int index, int counter){
    if(index == counter){
        struct nodeList* rightSide = head->next->next;
        free(head->next);
        head->next = rightSide;
        return;
    }
    _removeByIndexList(head->next, index, counter + 1);
}

int removeByIndexList(lList* base, int index){
    if(base->head == NULL){
        return 1;
    }
    if(index > base->size || index < 0){
        return 1;
    }
    if(index == 0){
        struct nodeList* rightSide = base->head->next;
        free(base->head);
        base->head = rightSide;
        base->size--;
        return 0;
    }
    _removeByIndexList(base->head, index, 1);
    base->size--;
    return 0;
}

int _removeByValueList(struct nodeList* head, int val){
    if(head->next->val == val){
        struct nodeList* rightSide = head->next->next;
        free(head->next);
        head->next = rightSide;
        return 0;
    }
    if(head->next->next == NULL){
        return 1;
    }
    return _removeByValueList(head->next, val);
}

int removeByValueList(lList* base, int val){
    if(base->head == NULL){
        return 1;
    }
    if(base->head->val == val){
        struct nodeList* rightSide = base->head->next;
        free(base->head);
        base->head = rightSide;
        base->size--;
        return 0;
    }

    if(!_removeByValueList(base->head, val)){
        base->size--;
        return 0;
    }
    return 1;
}
