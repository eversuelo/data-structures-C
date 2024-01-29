#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Structure of a node in a linked list
 */
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
/**
 * @brief Create a Node object
 * @param value Valuf of the node
 * @param next Pointer to the next node
 * @return Node*
 */
Node *createNode(int value, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = next;
}
typedef struct LinkedList
{
    Node *head;
} LinkedList;
LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}
void insertNode(LinkedList *list, int value)
{
    list->head = createNode(value, list->head);
}
void insertAteND(LinkedList *list, int value)
{
    Node *head = list->head;
    Node *tempNode = createNode(value, NULL);
    if (head == NULL)
    {
        list->head = tempNode;
    }
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = tempNode;
}
void printList(LinkedList *list)
{
    Node *head = list->head;
    printf("[");
    while (head)
    {
        printf("%d", head->value);
        head = head->next;
        if (head != NULL)
        {
            printf(",");
        }
    }
    printf("]\n");
}
int findLength(LinkedList *list)
{
    Node *head = list->head;
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}
void sortedInsert(LinkedList *list, int value)
{
    Node *head = list->head;
    Node *tempNode = createNode(value, NULL);
    if (head == NULL || head->value > value)
    {
        tempNode->next = head;
        list->head = tempNode;
        return;
    }
    while (head->next != NULL && head->next->value < value)
    {
        head = head->next;
    }
    tempNode->next = head->next;
    head->next = tempNode;
}
/**
 * @brief Return the index of the value in the linked list, if not found return -1
 *
 * @param list LinkedList Where we want to search
 * @param value value that we want to search
 * @return int
 */
int searchList(LinkedList *list, int value)
{
    Node *head = list->head;
    int index = 0;
    while (head)
    {
        if (head->value == value)
        {
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}
void deleteFirstNode(LinkedList *list, int n)
{
    Node *head = list->head;
    if (head == NULL)
        return;
    Node *next=head->next;
    free(head);
    list->head=next;
}

void deleteNode(LinkedList *list, int delValue){
    Node *head = list->head;
    if (head == NULL)
        return;
    if (head->value==delValue){
        deleteFirstNode(list,delValue);
        return;
    }
    Node *prev=head;
    while (head!=NULL && head->value!=delValue){
        prev=head;
        head=head->next;
    }
    if (head==NULL)
        return;
    prev->next=head->next;
    free(head);
    
}
