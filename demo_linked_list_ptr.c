// An example to show how to use a linked list

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* typedef a structure named Dict (dictionary)
 * In the dictionary, you have items with keys and values
 * Here I define the key is an integer and the value is
 * a pointer
 * The code here can be used to:
 *  1) create a dict
 *  2) print a dict
 *  3) add an item
 *  4) delete an item
 *  5) reverse all items and
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

//create a dict
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

//print the items in a dict
int Dict_Print(dict_t *pHead){
    dict_t *tmp;
    if (pHead == NULL) return -1;
    tmp = pHead->pNext;
    printf("\n=====================================");
    printf("\nBegin\n\tThe dict is:\n\t{\n");
    while (tmp){
        printf("\t\t%d:%s\n", tmp->Key, tmp->Value);
        tmp = tmp->pNext;
    }
    printf("\t}\nEnd\n");
    printf("=====================================\n");
    return 0;
}

//check if an item exits
int check_item(dict_t *pHead, int key){
    dict_t *pCurrent, *pPrevious;

    pPrevious = pHead;
    pCurrent = pHead->pNext;

    while (pCurrent)
    {
        if (pCurrent->Key == key)
        {
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent == NULL)
    {
        //printf("No item with a key: '%d' found. Abort!\n", tgtKey);
        return -1;
    }
    return 0;
}

// insert an new item before an exiting item with a given key
// if the key already exits, update the value
int Item_insert(dict_t *pHead, int tgtKey, int newKey, char *newValue){
    dict_t *pCurrent, *pPrevious, *pNew;

    pNew = (dict_t *)malloc(sizeof(dict_t));
    if (pNew  == NULL) return -1;

    pNew->Key = newKey;
    pNew->Value = newValue;
    pNew->pNext = NULL;

    pPrevious = pHead;
    pCurrent = pHead->pNext;

    if (check_item(pHead, tgtKey) == -1) {
        printf("No such an item with a key: '%d' found. Abort!\n", tgtKey);
        return -2;
    }

    while (pCurrent)
    {
        if (pCurrent->Key == tgtKey) {
            break;
        }
        if (pCurrent->Key == newKey){
            pCurrent->Value = newValue;
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

int Item_delete(dict_t *pHead, int tgtKey){
    dict_t *pCurrent, *pPrevious;

    pPrevious = pHead;
    pCurrent = pHead->pNext;

    while (pCurrent)
    {
        if (pCurrent->Key == tgtKey)
        {
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent == NULL)
    {
        printf("No such an item with a key: '%d' found. Abort!\n", tgtKey);
        return -1;
    }

    pPrevious->pNext = pCurrent->pNext;
    if(pCurrent != NULL)
    {
        free(pCurrent);
    }
    return 0;
}

int Dict_Destory(dict_t *pHead)
{
    dict_t *tmp;
    if (pHead == NULL)
    {
        return -3;
    }

    while (pHead != NULL)
    {
        tmp = pHead->pNext;
        free(pHead);
        pHead = tmp;
    }
    return 0;
}

int main(){
    int ret = 0;
    dict_t *pHead = NULL;
    printf("\n*************** Starting to create a dict ***************\n");
    pHead = Dict_Create();
    printf("\n**************** Completing the creation ****************\n");
    ret = Dict_Print(pHead);
    printf("\n### add or update an item \n");
    ret = Item_insert(pHead, 20, 10, "test");
    ret = Dict_Print(pHead);
    printf("\n### delete an item \n");
    ret = Item_delete(pHead, 20);
    ret = Dict_Print(pHead);
    ret = Dict_Destory(pHead);

    return ret;
}
