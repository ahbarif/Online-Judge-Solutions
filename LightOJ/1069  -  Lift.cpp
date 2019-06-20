#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	
	int a, b, diff, test, i;
	cin >> test;

	for (i = 1; i <= test; i++)
	{	
		cin >> a >> b;
		diff = 4 * abs(a - b);
		cout <<"Case "<<i<<": "<< diff + 19 + (a * 4)<<endl;
	}
	return 0;
}