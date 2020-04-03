// An example to show how to use a linked list

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 128 // max length of a string

/* typedef a structure named Dict (dictionary)
 * In the dictionary, you have items with keys and values
 * Here I define the key is a integer and the value is
 * a string without whitespaces split
 * The code here can be used to:
 *  1) create a dict
 *  2) print a dict
 *  3) add an item
 *  4) delete an item 
 *  5) reverse all items and
 *  6) destroy a dict
 *
 * Note: When key == -1, the program completes.
 */

/* TODO:
*  1) Try to use a pointer to present a string
*  2) How to read a string with whitespaces
*/

typedef struct Node{
    int Key;
    char Value[MAX];
    struct Node *pNext;
}Dict_t;

Dict_t *Dict_Create() {
    Dict_t *pHead, *pCurrent, *pNew;
    int key;
    char value[MAX];

    pHead = (Dict_t *) malloc(sizeof(Dict_t));
    if (pHead == NULL) return NULL;
    pHead->Key = 0;
    strcpy(pHead->Value, "0");
    pHead->pNext = NULL;

    printf("\nPlease enter the key [int]: ");
    scanf("%d", &key);
    if (key == -1) return NULL;

    getchar(); // important here
    printf("Please enter the value [str]: ");
    scanf("%s", value);

    pCurrent = pHead;
    while (key != -1) {
        pNew = (Dict_t *) malloc(sizeof(Dict_t));
        if (pNew == NULL) return NULL;
        pNew->Key = key;
        strcpy(pNew->Value, value);
        pNew->pNext = NULL;
        pCurrent->pNext = pNew;
        pCurrent = pNew;
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
int Dict_Print(Dict_t *pHead){
    Dict_t *tmp;
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

int main(){
    int ret = 0;
    Dict_t *pHead = NULL;
    pHead = Dict_Create();
    ret = Dict_Print(pHead);
    return ret;
}
