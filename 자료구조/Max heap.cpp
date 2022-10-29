#include <cstdio>

int num[1000001] = { 0, };

void left_child(int i);
void right_child(int i);
int pop();

// Max Heap을 이용하여N개의 수를 주어준 후 N개의 값을 입력받아 오름차순으로 출력
// 배열값이 0 이면 노드가 없는 값으로 판별하게 해놨기 때문에 0보다 큰 값들만 가능함
int main() {

	int N;
	scanf_s("%d", &N);

	scanf_s("%d", &num[1]);
	for (int i = 2; i <= N; i++)
	{
		scanf_s("%d", &num[i]);

		if (i % 2 == 0)
		{
			left_child(i);
		}
		else
		{
			right_child(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		printf("%d\n", pop());
	}

	return 0;
}

void left_child(int i) 
{
	int temp;

	if (num[i / 2] < num[i])
	{
		temp = num[i / 2];
		num[i / 2] = num[i];
		num[i] = temp;
		
		if (i / 2 > 1)
		{
			if ((i / 2) % 2 == 0)
				left_child(i / 2);
			else
				right_child(i / 2);
		}
	}
}

void right_child(int i) 
{
	int temp;

	if (num[(i-1) / 2] < num[i])
	{
		temp = num[(i-1) / 2];
		num[(i-1) / 2] = num[i];
		num[i] = temp;
		if ((i - 1) / 2 > 1)
		{
			if (((i - 1) / 2) % 2 == 0)
				left_child((i-1) / 2);
			else
				right_child((i-1) / 2);
		}
	}
}

int pop() {

	int result = num[1];
	int i = 1;
	while (1)
	{

		if (num[2 * i] == 0 && num[2 * i + 1] == 0)
		{
			num[i]=0;
			break;
		}

		if (num[2 * i] < num[2 * i + 1])
		{
			num[i] = num[2 * i + 1];
			i = 2 * i + 1;
		}
		else
		{
			num[i] = num[2 * i];
			i = 2 * i;
		}

	}

	return result;
}