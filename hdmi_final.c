/* Conditions 
1. HDMI total Input 8, total output 1
2. Remember orders that you plug in
3. When plug out, reconnect to last one */

// Managing Array's Location version <--- this case 
// Managing Array's value position version 

// Currently duplicate numbers are allowed
// To do later: Remove duplicate numbers when putting nums

#include <stdio.h>
#include <stdlib.h> // for exit(0)

#define SIZE 8
#define Out_default 1

// declare global variable for queue 
int Rear = -1;
int Front = -1;
char Input[SIZE]; // 활용은 큐냐 스택이냐 선택에 따라 다름
int plugin_num;

// queue func
void Plugin();
void Unplug();
void Display();

int main()
{
    int choice;
	for (int i=0;i<SIZE;i++) // initialize arrary
	{
		Input[i] = 0;
		//printf("%d ",Input[i]);
	}
		

    while(1)
    {
	    printf("1. To Plugin \n");
		printf("2. To Unplug \n");
		printf("3. Display Current State \n");
		printf("4. Exit\n");
		printf("Enter for operations : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Plugin();
			break;
		case 2:
			Unplug();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0); // exit while
		default:
			printf("Wrong Choice \n");
			break;
        }
    }
}

void Plugin()
{
	if (Front == SIZE - 1)
		printf("Element is Packed. Please try other operation");
	else
	{
		if (Front == -1)
			Front = 0;
		printf("\n");
		printf("Which location to plugin HDMI: ");
		scanf("%d", &plugin_num);
		Rear = Rear + 1;
		Input[Rear] = plugin_num;
	}
	printf("\n");
}

void Unplug()
{
    int del_ele, i, idx;

    printf("\n");
    printf("Unplug location: \n"); 
    scanf("%d", &del_ele);

    for(i = 0; i < SIZE; i++)
    {
        if(Input[i] == del_ele)
        {
            idx = i;
            break;
        }
    }

    //shift all the element from index+1 by one position to the left
	for(i = idx; i < SIZE-1 ; i++) // work for only Input[6]
		Input[i] = Input[i+1];

	if (Rear == -1)
	{
		printf("Underflow!\n"); //rear -1 일때 빼면 안됨. error case.
	}
	else
		Rear = Rear - 1;  

    printf("\n");
}

void Display()
{
	if (Front == -1)
		printf("Nothing to Display \n");
	else
	{
		printf("Current Display (Queue): \n");

		for (int i = Front; i <= Rear; i++)
			printf("%d ", Input[i]);
		printf("\n");
	}
	printf("\n");
}