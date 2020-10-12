#include<stdio.h>
#include<stdlib.h>

int biggest(int a[], int n)
{
    int i, largest_data;
    largest_data = a[0];

    for ( i = 0; i < n; i++)
    {
        if(a[i] > largest_data)
            largest_data = a[i];
    }
    return largest_data;   
}

void radixSort(int a[], int n)
{
    int **radix = NULL, radixContainer[10];
    int i,j = 0,k, NOP = 0, largest, remainder, divisor = 1, passes;

    radix = (int **) calloc (10, sizeof(int*));

    for ( i = 0; i < 10; i++)
    {
        radix[i] = (int *) calloc (n, sizeof(int));
    }
    
    largest = biggest(a, n);

    while (largest > 0)
    {
        NOP++;
        largest /= 10;
    }
    

    for ( passes = 0; passes < NOP; passes++)
    {   
        printf("ENTERING PASS --> %d\n\n", passes);
        for ( i = 0; i < 10; i++)
            radixContainer[i] = 0;
        
        j = 0;
        for ( i = 0; i < n; i++)
        {
            printf("a[%d] --> %d\n", i, a[i]);
            remainder = (a[i] / divisor) % 10;
            printf("remainder (%d) --> ( a[%d](%d) / %d ) '%' %d\n", remainder, i, a[i], divisor, 10);
            j = radixContainer[remainder];
            printf("j --> %d\n", j);
            radix[remainder][radixContainer[remainder]] = a[i];
            
            printf("radix[%d][%d] --> %d\n", remainder, j, radix[remainder][j]);
            radixContainer[remainder]++;
            printf("j --> %d\n", j);
        }
        
        i = 0;
        for ( k = 0; k < 10; k++)
        {   
            printf("Now Copying the elements\n");
            for (j = 0; j <= radixContainer[k]; j++)
            {   
                if(radix[k][j] == 0)
                    continue;
                else
                {
                    a[i] = radix[k][j];
                    printf("Copying radix[%d][%d] (%d) --> a[%d] (%d)\n", k,j,radix[k][j],i,a[i]);
                    i++;
                    radix[k][j] = 0;
                }
                
                   
            }
        }
        
        divisor *= 10;
    }
    

}

void print(int a[], int n)
{
    int i;
    printf("So now Printing the Array below:\n");

    for ( i = 0; i < n; i++)
    {
        printf("%c%4d%c\n", 221, a[i], 222);
    }
}

void main()
{   int length, i;
    printf("Welcome to Radix Sort!!\n");
    printf("I can Sort integer data elements for You if you want\n");
    printf("At least give it a Try!\n");


    printf("So Let me know how much data elements you want:\n");
    scanf("%d", &length);
    
    int *a = (int *) calloc (length, sizeof(int));
    int *b = (int *)calloc (length, sizeof(int));
    
    printf("Now Please enter the data elements below:\n");
    for ( i = 0; i < length; i++)
    {
        scanf("%d",&a[i]);
    }
    
    radixSort(a, length);

    print(a, length);    

    printf("Thanks for Investing time in Me!!");
}