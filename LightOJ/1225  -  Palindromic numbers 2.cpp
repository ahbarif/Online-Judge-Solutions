#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int test, i, a, num, reminder, sum = 0;

	scanf("%d", &test);
	for (i = 1; i <= test; i++)
	{
		scanf("%d", &num);
		a = num;
		sum = 0;

		while (num > 0)
		{
			reminder = num % 10;
			sum = sum * 10 + reminder;
			num = num / 10;
		}

		if (a == sum)
		{
			printf("Case %d: Yes\n", i);
		}
		else
			printf("Case %d: No\n", i);
	}
	return 0;
}