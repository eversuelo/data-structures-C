#include "./Structure/LinkedList.h"
#include <time.h>
int main(int argc, char *argv[])
{
    int n = 0;
    srand(time(NULL));
    if (argc != 2)
    {
        printf("We expected at least one number. For example: main 100 \n");
        return 0;
    }
    else
    {
        n = atoi(argv[1]);
    }
    LinkedList *list = createLinkedList();
    for (int i = 0; i <= n; i++)
    {
        // Randum Insert
        sortedInsert(list, rand() % 100);
    }
    printList(list);
    printf("Length of list: %d\n", findLength(list));
    printf("Give me a number(to search in Linked List): ");
    int value;
    scanf("%d", &value);
    printf("The number %d is in the list: %s, in index %d\n", value, searchList(list, value)==-1 ? "false" : "true",searchList(list, value));
    return 1;
}