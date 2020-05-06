#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <string.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
 }NODE, *pNODE_t;

pNODE_t CreatNode()
{
    int n;
    pNODE_t pHead = (pNODE_t)malloc(sizeof(NODE));
    pNODE_t pcurrent = pHead;

    for ( int i = 1, n = 7; i <=3; ++i, ++n)
    {
        pNODE_t pNew= (pNODE_t)malloc(sizeof(NODE));
        pNew->val = n;
        pNew->next = NULL;
        pcurrent->next = pNew;
        pcurrent = pNew;
    }
    return pHead;
}

pNODE_t CreatNode2()
{
    int n;
    pNODE_t pHead = (pNODE_t)malloc(sizeof(NODE));
    pNODE_t pcurrent = pHead;

    for ( int i = 1, n = 5; i <=4; ++i, ++n)
    {
        pNODE_t pNew= (pNODE_t)malloc(sizeof(NODE));
        pNew->val = n;
        pNew->next = NULL;
        pcurrent->next = pNew;
        pcurrent = pNew;
    }
    return pHead->next;
}

int ListLen(pNODE_t List)
{
    int len = 0;
    pNODE_t p = List;
    while (NULL != p->next){
        len++;
        p = p->next;
    }
    return len;
}


int getElement(pNODE_t List, int len, int pos)
{
    int i = 0;
    pNODE_t p = List;
    if(pos > len)
        return 0;
    else
    {
        while(NULL != p->next && i != pos)
        {
            p = p->next;
            i++;
        }
        return p->val;
    }

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int lenl1 = ListLen(l1);
    int lenl2 = ListLen(l2);
    int overflow = 0, Len, el1, el2, el;
    Len = lenl1 >= lenl2 ? lenl1: lenl2;
    pNODE_t pHead = (pNODE_t)malloc(sizeof(NODE));
    pNODE_t pcurrent = pHead;

    for (int i = 1;  i <= Len + 1; i++)
    {
        el1 = getElement(l1, lenl1, i);
        el2 = getElement(l2, lenl2, i);
        el = el1 + el2 + overflow;
        if (el >=10)
        {
            el = el % 10;
            overflow = 1;
        }
        else
            overflow = 0;
        if (i > Len && el == 0)
            return pHead;
        pNODE_t pNext = (pNODE_t)malloc(sizeof(NODE));
        pNext->val = el;
        pcurrent->next = pNext;
        pNext->next = NULL;
        pcurrent = pNext;

    }
    return pHead;
}

void traverse(pNODE_t pHead)
{
    pNODE_t p = pHead->next;
    while(NULL != p)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ll1, *ll2;
    struct ListNode *head = NULL;
    struct ListNode **lp = &head;
    int carry = 0, sum = 0, val1, val2;
    for (ll1 = l1, ll2 = l2; ll1 || ll2;) {
        val1 = ll1 ? ll1->val : 0;
        val2 = ll2 ? ll2->val : 0;
        sum = val1 + val2 + carry;
        *lp = malloc(sizeof(struct ListNode));
        (*lp)->val = sum % 10;
        (*lp)->next = NULL;
        carry = sum / 10;
        lp = &(*lp)->next;
        ll1 = ll1 ? ll1->next : NULL;
        ll2 = ll2 ? ll2->next : NULL;
    }
    if (carry) {
        *lp = malloc(sizeof(struct ListNode));
        (*lp)->val = carry;
        (*lp)->next = NULL;
    }
    return head;
}

int main()
{
    pNODE_t pHead1 = CreatNode();
    traverse(pHead1);
    pNODE_t pHead2 = CreatNode2();
    traverse(pHead2);
	
	pNODE_t test = addTwoNumbers1(pHead1, pHead2);
	traverse(test);

    pNODE_t test = addTwoNumbers2(pHead1, pHead2);
    traverse(test);
}
