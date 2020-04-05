// An example to show how to use a linked list

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 128 // max length of a string

/* typedef a structure named Dict (dictionary)
 * In the dictionary, you have items with keys and values
 * Here I define the key is an integer and the value is
 * a pointer
 * The code here can be used to:
 *  1) create a dict
 *  2) print a dict
 *  3) add an item
 *  4) delete an item and
 *  5) reverse all items
 *  6) destory the dict
 *
 * Note: When key == -1, the program stops.
*/

/* TODO:
*  1) How to catch the stdin with whitespaces
*/

typedef struct Node{
    int Key;
    char *Value;
    struct Node *pNext;
}dict_t;

dict_t *Dict_Create() {
    dict_t *pHead, *pCurrent, *pNew;
    int key;
    char *value;

    value = (char *)malloc(sizeof(char));
    if (value == NULL) return NULL;

    pHead = (dict_t *) malloc(sizeof(dict_t));
    if (pHead == NULL) return NULL;

    pHead->Key = 0;
    pHead->Value = NULL;
    pHead->pNext = NULL;

    printf("\nPlease enter your key [int]: ");
    scanf("%d", &key);
    if (key == -1) return NULL;

    getchar(); // important here
    printf("Please enter the value [str]: ");
    scanf("%s", value);

    pCurrent = pHead;
    while (key != -1) {
        pNew = (dict_t *) malloc(sizeof(dict_t));
        if (pNew == NULL) return NULL;
        pNew->Key = key;
        pNew->Value = value;
        pNew->pNext = NULL;
        pCurrent->pNext = pNew;
        pCurrent = pNew;
        value = (char *)malloc(sizeof(char));
        getchar();
        printf("\nPlease enter your key [int]: ");
        scanf("%d", &key);
        if (key == -1) return pHead;
        getchar();
        printf("Please enter the value [str]: ");
        scanf("%s", value);
    }
    return pHead;
}

int Dict_Print(dict_t *pHead){
    dict_t *tmp;
    if (pHead == NULL) return -1;
    tmp = pHead->pNext;
    printf("\nBegin\n\tThe dict is:\n\t{\n");
    while (tmp){
        printf("\t\t%d:%s\n", tmp->Key, tmp->Value);
        tmp = tmp->pNext;
    }
    printf("\t}\nEnd\n");
    return 0;
}

int Item_insert(dict_t *pHead, int tgtKey, int Key, char *Value){
    dict_t *pCurrent, *pPrevious, *pNew;

    pNew = (dict_t *)malloc(sizeof(dict_t));
    if (pNew  == NULL) return -1;

    pNew->Key = Key;
    pNew->Value = Value;
    pNew->pNext = NULL;

    pPrevious = pHead;
    pCurrent = pHead->pNext; //pPre->next

    while (pCurrent)
    {
        if (pCurrent->Key == tgtKey) {
            break;
        }
        if (pCurrent->Key == Key){
            pCurrent->Value = Value;
            goto END;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    pNew ->pNext = pPrevious->pNext;
    pPrevious->pNext = pNew;
    goto END;
    END:
        return 0;
}

int main(){
    int ret = 0;
    dict_t *pHead = NULL;
    pHead = Dict_Create();
    ret = Item_insert(pHead, 20, 10, "test");
    ret = Dict_Print(pHead);

    return ret;
}
