#include<stdio.h>
#include<stdlib.h>

int biggest(int a[], int n)
{
    int i, largest_data;
    largest_data = a[0];

    // Trying to find the Largest of all the integers in the Array
    for ( i = 0; i < n; i++)
    {
        if(a[i] > largest_data)
            largest_data = a[i];
    }
    return largest_data;   
}

void radixSort(int a[], int n)
{   
    // The Bucket Container will have 10 elements because we have the digits 0-9
    int **radix = NULL, radixContainer[10];

    // Number of Passes (NOP)
    int i, j, k, NOP = 0, largest, remainder, divisor = 1, passes;

    /* The Bucket will have 10 rows (because of 0-9 digits) and 'n' columns
       Hence we have to allocate the memory for this 2D array because the value of 'n' is Dynamic
       So we allocated the 10 rows using the calloc function
       And after that every column should have 10 elements i.e. row, col: 0,1 ; 0,2 ; 0,3 ; 0,4 ; .... ; 0,9
       Hence we have to allocate this memory for every column & we do it using a for loop
    */
    radix = (int **) calloc (10, sizeof(int*));

    for ( i = 0; i < 10; i++)
    {
        radix[i] = (int *) calloc (n, sizeof(int));
    }
    
    // We store the largest value in the Array
    largest = biggest(a, n);

    // Finding out the Number of Passes needed
    while (largest > 0)
    {
        NOP++;
        largest /= 10;
    }
    
    // The passes are dependent on the Largest integer in the Array
    for ( passes = 0; passes < NOP; passes++)
    {   
        printf("ENTERING PASS --> %d\n\n", passes);
        /* Initializing the elements of the Bucket Container to 0
            We use the Bucket container to appropriately place the element in the 2D array
            i.e. it Decides the column no.
        */
        for ( i = 0; i < 10; i++)
            radixContainer[i] = 0;
        
        // We place the elements of the Array according to the (Time --->) : Units, Tense, Hundreds,....
        for ( i = 0; i < n; i++)
        {
            printf("a[%d] --> %d\n", i, a[i]);
            // We Find the Units or Tense or Hundreds place of an integer
            remainder = (a[i] / divisor) % 10;
            printf("remainder (%d) --> ( a[%d](%d) / %d ) '%' %d\n", remainder, i, a[i], divisor, 10);
            j = radixContainer[remainder];
            printf("j --> %d\n", j);
            // Now we Store the Integer according to the Remainder in the Bucket with the Help of Bucket Container
            radix[remainder][radixContainer[remainder]] = a[i];
            
            printf("radix[%d][%d] --> %d\n", remainder, j, radix[remainder][j]);
            // We Increment the value in the Bucket Container by 1 as we encounter an integer
            radixContainer[remainder]++;
            printf("j --> %d\n", j);
        }
        
        // Now we Copy the elements in the Bucket into the Array
        i = 0;
        // Since there are 10 rows we have to go throught each row
        for ( k = 0; k < 10; k++)
        {   
            printf("Now Copying the elements\n");
            // Since the columns are decieded by Bucket Container the condition depends upon that 
            for (j = 0; j <= radixContainer[k]; j++)
            {   
                // We only have to Copy the Values that were the original part of the Array & we don't want any other values to be copied 
                if(radix[k][j] == 0)
                    continue;
                else
                {   
                    // Copying the integers back to the Array
                    a[i] = radix[k][j];
                    printf("Copying radix[%d][%d] (%d) --> a[%d] (%d)\n", k,j,radix[k][j],i,a[i]);
                    // Incrementing the index of the Array
                    i++;
                    // Since the value has been copyied or assigned to the Array it doesn't has to repeat in the Bucket again we now don't need it
                    radix[k][j] = 0;
                }
                
                   
            }
        }
        // After ever pass is complete the Divisor becomes 10 times of itself
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
    
    // Creating an array using calloc i.e. array for the user defined length
    int *a = (int *) calloc (length, sizeof(int));
    
    // Accepting the data elements for the array
    printf("Now Please enter the data elements below:\n");
    for ( i = 0; i < length; i++)
    {
        scanf("%d",&a[i]);
    }
    
    // Sorting the Array in Ascending Order by using Radix Sort
    radixSort(a, length);
    
    // Printing the Array
    print(a, length);    

    printf("Thanks for Investing time in Me!!");
}