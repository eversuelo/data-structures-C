#include <stdio.h>

// Function Declaration
int neestedLoop(int n)
{
    int no_instructions=0;  
    for (int i = 0; i < n; i++)
    {
        printf("First Cycle: %d\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("\tSecond Cycle: %d\n", j);
            no_instructions+=1;
        }
    }
    return no_instructions;
}
int main()
{
    int n;
    printf("Enter a number n loop: ");
    scanf("%d", &n);
    int no=neestedLoop(n); // Function Call
    printf("Number of times loop executed: %d equals to number of instructions\nAlgorithm is Big O(n*n)\n", no);
    return 0;
}