#include <cstdio>

//20층까지 가능 2^20 이상
//메모리 비효율이 엄청남
int num2[1100000] = { 0, };
void left(int a, int b);
void right(int a, int b);
int right_check(int b);
int left_check(int b);


int main() {

	int N, k;
	scanf_s("%d", &N);

	scanf_s("%d", &k);
	num2[1] = k;

	for (int i = 1; i < N; i++)
	{
			scanf_s("%d", &k);

			if (k < num2[1])
				left(k, 1);
			else
				right(k, 1);
	}

	int t = right_check(1);				//최대값의 인덱스값
	int min = left_check(1);            //최소값의 인덱스값

	while (1) {
		if (num2[t * 2] == NULL) {
			printf("%d\n", num2[t]);
			if (t == min)
				break;

			if ((t - 1) % 2 == 1) {
				while ((t - 1) % 2 != 0) {
					t = t / 2;
				}
				t = (t - 1) / 2;
			}
			else
				t = (t - 1) / 2;
		}

		else {
			printf("%d\n", num2[t]);
			t = right_check(t * 2);
		}

	}

	return 0;
}

void left(int a, int b)
{
	if (num2[b * 2] == NULL)
		num2[b * 2] = a;
	else if (num2[b * 2] < a)
		right(a, b * 2);
	else
		left(a, b * 2);
}

void right(int a, int b)
{
	if (num2[b * 2 + 1] == NULL)
		num2[b * 2 + 1] = a;
	else if (num2[b * 2 + 1] < a)
		right(a, b * 2 + 1);
	else
		left(a, b * 2 + 1);
}

int right_check(int b)
{
	if (num2[b * 2 + 1] == NULL)
		return b;
	else
		right_check(b * 2 + 1);
}

int left_check(int b)
{
	if (num2[b * 2] == NULL)
		return b;
	else
		left_check(b * 2);
}