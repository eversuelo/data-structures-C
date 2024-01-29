#include <stdio.h>

// Function Declaration
void loop(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", i);
    }
}
int main()
{
    int n;
    printf("Enter a number n loop: ");
    scanf("%d", &n);
    loop(n); // Function Call
    printf("Number of times loop executed: %d equals to number of instructions\n", n);
    return 0;
}