#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	long int test, i, a, b, c;
	cin >> test;

	for (i = 1; i <= test; i++)

	{
		cin >> a >> b >> c;

		if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
		{
			cout << "Case " << i << ": yes" << endl;
		}
		else
		{
			cout << "Case " << i << ": no" << endl;
		}
	}
	return 0;
}