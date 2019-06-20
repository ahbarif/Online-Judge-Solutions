# include<iostream>
# include<iomanip>
# include<string>
# include<algorithm>
# include<vector>
# include<set>
# include<iterator>
# include<stack>
# include<queue>
# include<math.h>
# include<cstdio>
# include<functional>
using namespace std;
int divo[10003];

inline string multiply(string a, int b) {

	int carry = 0;

	for (int i = 0; i < a.size(); i++)
	{
		carry += (a[i] - 48) * b;
		a[i] = (carry % 10 + 48);
		carry /= 10;
	}

	while (carry)
	{
		a += (carry % 10 + 48);
		carry /= 10;
	}

	return a;
}

inline void factorize(int n)
{
	int i, p = 0;

	if (n % 2 == 0)
	{
		while (n % 2 == 0)  p++, n /= 2;
		divo[2] = max(p, divo[2]);
	}

	for (i = 3; i*i <= n; i += 2)
	{
		p = 0;
		if (n%i == 0)
		{
			while (n%i == 0)   ++p, n /= i;
			divo[i] = max(divo[i], p);
		}
	}

	if (n>1) p = 1, divo[n] = max(divo[n], p);

}

int main()
{
	int test, caseno = 0, i, n, x;

	string s;

	cin >> test;

	while (test--)
	{

			memset(divo, 0, sizeof(divo));
			s = "1";

			cin >> n;

			for (i = 0; i<n; i++)
			{
				cin >> x;
				factorize(x);
			}

			for (i = 0; i<10000; i++)
			{
				if (divo[i])
				{
					x = ceil(pow(i, divo[i]));
				//	cout << i << " = " << divo[i] << endl;
					s = multiply(s, x);
				}
			}

			reverse(s.begin(), s.end());

			cout <<"Case "<<++caseno<<": "<< s << endl;

	}

	return 0;
	

}