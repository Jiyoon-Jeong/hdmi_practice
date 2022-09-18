/* Conditions 
1. HDMI total Input 8, total output 1
2. Remember orders that you plug in
3. When plug out, reconnect to last one */

#include <stdio.h>
#define SIZE 8
#define Out_default 1

// implement func 
void Display();

// global variable for queue
int Front = -1;
int Rear = -1;
unsigned char Input[SIZE];

int main()
{
	int Choice;
	//for(int i = 1; i < 9 ; i++) // 1개만 꽂고 싶을 때는?? 
	while(1)
	{
		//printf("Enter to plugin: ");
		//scanf_s("%d", Input[i]);
		printf("1. To Plugin \n");
		printf("2. To Unplug \n");
		prinft("3. Display Current State \n");
		printf("4. Exist\n");
		printf("Enter for operations :");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			Pulgin();
			break;
		case 2:
			Unplug();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0) // exit while
		default:
			printf("Wrong Choice \n");
			break;
		}
	}

	//for (int i = 1; i<9; i++)
		//printf("Current Input: %d, Current Output: %d", Input[SIZE], Output);
	//return 0;
}

void Plugin()
{
	int plugin_num;
	if (Rear == SIZE - 1)
		//printf("Overflow \n");
		printf("Turn to Default Setting: %d", Out_default)
	else
	{
		if (Front == -1)
			Front = 0;
		printf("Which location to plugin HDMI: ");
		scanf("%d", % plugin_num);
		Rear = Rear + 1;
		Intput[Rear] = plugin_num;
	}
}

void Unplug()
{
	if (Front == -1 || Front > Rear)
		//printf("Underflow \n");
		printf("Turn to Default Setting: %d", Out_default)
	else
	{
		printf("Which location to unplug : %d \n", Intput[Front]);
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
			printf("%d", Input[i]);
		printf("\n");
	}
}