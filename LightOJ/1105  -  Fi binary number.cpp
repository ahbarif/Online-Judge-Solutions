#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[105];

void preCal()
{
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i < 60; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

int main()
{

//	freopen("in.txt", "r", stdin);

	preCal();

	int test, cs = 0;

	scanf("%d", &test);

	while (test--)
	{

		long long n;

		scanf("%lld", &n);

		printf("Case %d: ", ++cs);

		bool flag = false;

		for (int i = 50; i >= 1; i--)
		{
			if (n >= fib[i])
			{
				n -= fib[i];
				printf("1");
				flag = true;
			}
			else
			{
				if (flag)	printf("0");
			}
		}
		puts("");
	}
}
