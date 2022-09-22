/* Conditions 
1. HDMI total Input 8, total output 1
2. Remember orders that you plug in
3. When plug out, reconnect to last one */

/* 결국, 스택으로 가장 나중을 보여주되 큐를 섞어서 중간값을 
삭제했을 시 가장 마지막 남은 값은 냅두고 그 뒤부터 하나씩 가져오게*/

// history로 (시간) 관리
// 단지 플러그 단자로만 꽂으면 알기가 어떤게 먼저이고 나중인지 알기가 어려움.

// 현 상태: 중복값이 허용됨. 

#include <stdio.h>
#include <stdlib.h> // for exit(0)

#define SIZE 8
#define Out_default 1

// declare global variable for queue 
int Rear = -1;
int Front = -1;
char Input[SIZE]; // 활용은 큐냐 스택이냐 선택에 따라 다름
int temp[SIZE];
int plugin_num;
int new_plugnum;

// queue func
void Plugin();
int Unplug();
void Display();


int main()
{
    int choice;
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
    //int new_plugnum;
	if (Rear == SIZE - 1)
		//printf("Overflow \n"); // can die, 1. Big data: auto variable should not use
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

		new_plugnum = plugin_num;
	}
	printf("\n");
}

// void Unplug() // FIFO 
// {
// 	if (Front == -1 || Front > Rear)
// 		//printf("Underflow \n");
//		printf("It's Empty, turn to default setting: %d", Out_default);
// 	else // FIFO
// 	{
// 		printf("Which location to unplug : %d \n \n", Input[Front]);
// 		Front = Front + 1;
// 	}
// }

int Unplug() // implement delete element in the middle
{
    // LIFO
	// printf("Which location to unplug: \n", Input[Rear]);
	// Rear = Rear - 1; // same as Input[Rear--]
	
	int del_ele, i, idx;

	printf("\n");
	//printf("Unplug location: %d \n", plugin_num); // plugin_num is the last number you put
	printf("Unplug location: \n"); 
	//scanf("%d", &Input[Front++]); // 1 2 3 -> 2 out: 0 0 . rear++ 1,2,3,-> 1,2,3,0.
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

	//Input[i] = 0; // last a[7] should be 0 after a num out. if this is not exist, critical bug issue comes out.
	
	for (i = SIZE -2; i>=0;i--) // 12450
		Input[i+1] = Input[i];
		Input[i+1] = 0; 

	printf("Current Input : "); // for debugging
	for(i = SIZE-1; i >= 0 ; i--)	//00054210	(for i=0;i<SIZE;i++) 01245000
		printf("%d ",Input[i]); // 2,5,6,0,7... (중간에 0이 안지워짐)
	

	// for (int i = 0; i <SIZE-1 ; i++)
	// 	Input[i] = Input[i+1];
	
	// Input[i] = new_plugnum; // need to erase 

	// for(int i=0;i<SIZE;i++) // for debugging
	// 	printf("%d ",Input[i]); 

	printf("\n");

	return 0;

}

void Display()
{
	if (Front == -1)
		printf("Nothing to Display \n");
	else
	{
		printf("Current Display (Queue): \n");

		for (int i = Front; i <= Rear; i++)
			printf(" %d ", Input[i]);
		printf("\n");
	}
	printf("\n");
}