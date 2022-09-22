// #include <stdio.h>

// #define SIZE 10

// int main()
// {
//     int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};
//     // remove one element 
//     int del;
//     int i;
//     int idx;
//     int input;
    
//     printf("Remove Num: \n");
//     scanf("%d", &del);

//     for (i = 0; i < SIZE ; i++)
//     {
//         if (arr[i] == del)
//             idx = i;
//             break;
//     }
    
//     if (idx != -1) 
//     {
//         for (i = idx; i < SIZE ; i++)
//             arr[i] = arr[i + 1]; // shifting to left. 

//         printf("New arr: ");
//         for (i = 0; i < SIZE -1; i++)
//             printf("%d ", arr[i]); // printout all nums except first element
//     }


//     return 0;
// }

#include<stdio.h>

#define size 5

int main()
{
    int arr[size];
    int key, i, num, index = -1;
    int new_num;
    
    //scanf("%d ", &arr[0]);
    printf("put numbers you want: ");
    for (num=0; num < size ;num++) // 대체 왜 하나를 더 받고 끝나지?? 
    {
        scanf("%d", &arr[num]); // & address ** study more
    printf("I get %d: ",arr[num]);
    }        
        
        printf("Current Array : ");
        for(i = 0; i < size ; i++)
            printf("%d ",arr[i]);
    
    printf("\nEnter element to delete: ");

    scanf("%d",&key);
    printf("I get %d: ",key);



    /*
     * iterate the array elements using loop
     * if any element matches the key, store the index
     */

    for(i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            index = i;
            break;
        }
    }

    //shift all the element from index+1 by one position to the left
    for(i = index; i < size -1; i++) // work for only arr[8]
        arr[i] = arr[i+1];

    arr[i] = 0; // last a[9] should be 0 after a num out

    printf("New Array : "); 
    for(i = 0; i < size ; i++)
        printf("%d ",arr[i]);

    printf("\nWant to need new num?: ");
    scanf("%d", &new_num);

    // get new number and shift numbs to right
    for (i = size -1; i >= 0 ; i--)
        arr[i+1] = arr[i];
    arr[0] = new_num;
    
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
        
    return 0;
}