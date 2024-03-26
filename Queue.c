#include <stdio.h>
#define SIZE 6

int main()
{
	int arr[SIZE] = { 0 };

	int First = 0, Last = 0;
	int Full = 0, Empty = 1;

	int value = 1;
	pushQueue(arr, value, &First, &Last, &Full, &Empty, SIZE);
	value = 2;
	pushQueue(arr, value, &First, &Last, &Full, &Empty, SIZE);
	int i;
	for (i = 0; i < 3; i++){
		pushQueue(arr, value, &First, &Last, &Full, &Empty, SIZE);
	}

	for (i = 0; i < SIZE; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	for (i = 0; i < 4; i++){
		popQueue(arr, &value, &First, &Last, &Full, &Empty, SIZE);
		printf("%d\n", value);
	}


}

int pushQueue(int *arr, int v, int *First, int *Last, int *F, int *E, int n)
{
	if (*F == 1){
		printf("Queue is full");
		return -1;
	}
	arr[*Last] = v;
	++*Last;
	*E = 0;
	return 0;
}

int popQueue(int *arr, int *v, int *First, int *Last, int *F, int *E, int n)
{
	if (*E == 1){
		printf("Queue is full");
		return -1;
	}
	*v = arr[*First];
	++*First;
	*F = 0;
	return 0;
}
