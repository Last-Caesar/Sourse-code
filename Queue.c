#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define SIZE 6

int pushQueue(int *arr, int v, int *First, int *Last, int *F, int *E, int n);
int popQueue(int *arr, int *v, int *First, int *Last, int *F, int *E, int n);
void printArr(int *arr, int n);

int main()
{
	int arr[SIZE] = { 0 }, value;

	int First = 0, Last = 0;
	int Full = 0, Empty = 1;

	printf("Press a key: Esc - to exit | 1 - to push a value in queue | 2 - to pop a value from queue\n");
	int exit = 0;
	while (!exit) {
		int c = _getch();
		switch (c)
		{
		case '1':
			printf("Enter a number\n");
			scanf("%d", &value);
			if (pushQueue(arr, value, &First, &Last, &Full, &Empty, SIZE) == -1)
				printf("Error: Queue is full\n");
			else
				printArr(arr, SIZE);
			break;
		case '2':
			if (popQueue(arr, &value, &First, &Last, &Full, &Empty, SIZE) == -1)
				printf("Error: Queue is empty\n");
			else{
				printf("%d\n", value);
				printArr(arr, SIZE);
			}
			break;
		case 27: // 27 mean "Esc"
			exit = 1;
			break;
		default:
			break;
		}
	}


}

int pushQueue(int *arr, int v, int *First, int *Last, int *F, int *E, int n)
{
	if (*F == 1){
		return -1;
	}
	arr[*Last] = v;
	++*Last;
	*E = 0;
	*Last %= n;
	if (*Last == *First){
		*F = 1;
	}
	return 0;
}

int popQueue(int *arr, int *v, int *First, int *Last, int *F, int *E, int n)
{
	if (*E == 1){
		return -1;
	}
	*v = arr[*First];
	arr[*First] = 0;
	++*First;
	*F = 0;
	*First %= n;
	if (*Last == *First){
		*E = 1;
	}
	return 0;
}

void printArr(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
