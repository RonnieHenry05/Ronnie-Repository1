#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head){
    int count = 0;
    node* counter = head;
    while(counter != NULL){
        count++;
        counter = counter-> next;
    }
    return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{if (head == NULL)
        return NULL;

    char* str = (char*)malloc((length(head) + 1) * sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    node* current = head;
    int i = 0;
    while (current != NULL) {
        str[i] = current->letter;
        current = current->next;
        i++;
    }
    str[i] = '\0'; 
    return str;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){
    node *t;
    node *temp;
    temp=(node *) malloc( sizeof(node));
    temp->letter= c;
    temp->next=NULL;
    if(*pHead==NULL)
        *pHead=temp;
    else
    {
        t=*pHead;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }

}
// deletes all nodes in the linkedList.
void deleteList(node** pHead){
    node* current = *pHead;
    node* nextnode;

    while (current != NULL) {
        nextnode = current->next;
        free(current);
        current = nextnode;
    }
    *pHead = NULL;
}
int main(void)
{
int i, strLen, numInputs;
node* head =NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
    fscanf(inFile," %c", &c);
    insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}