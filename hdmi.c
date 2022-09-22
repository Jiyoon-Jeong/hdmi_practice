/* Conditions 
1. HDMI total Input 8, total output 1
2. Remember orders that you plug in
3. When plug out, reconnect to last one */

/* 결국, 스택으로 가장 나중을 보여주되 큐를 섞어서 중간값을 
삭제했을 시 가장 마지막 남은 값은 냅두고 그 뒤부터 하나씩 가져오게*/

// history로 (시간) 관리
// 단지 플러그 단자로만 꽂으면 알기가 어떤게 먼저이고 나중인지 알기가 어려움. 

#include <stdio.h>
#include <stdlib.h> // for exit(0)
#define SIZE 8
#define Out_default 1

// global variable for queue
int Front = -1;
int Rear = -1;
unsigned char Input[SIZE];

void Plugin();
void Unplug();
void Display();

int main()
{
	int Choice;
	//for(int i = 1; i < 9 ; i++)  
	while(1)
	{
		//printf("Enter to plugin: ");
		//scanf_s("%d", Input[i]);
		printf("1. To Plugin \n");
		printf("2. To Unplug \n");
		printf("3. Display Current State \n");
		printf("4. Exit\n");
		printf("Enter for operations : ");
		scanf("%d", &Choice);
		switch (Choice)
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

	//for (int i = 1; i<9; i++)
		//printf("Current Input: %d, Current Output: %d", Input[SIZE], Output);
	return 0;
}

void Plugin()
{
	int plugin_num;
	if (Rear == SIZE - 1)
		//printf("Overflow \n"); // can die, 1. 큰 데이터 auto variable x 2. 
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

void Unplug() // FIFO
{
	if (Front == -1 || Front > Rear)
		//printf("Underflow \n");
		printf("It's Empty, turn to default setting: %d", Out_default);
	else // FIFO
	{
		printf("Which location to unplug : %d \n \n", Input[Front]);
		Front = Front + 1;
	}

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
}