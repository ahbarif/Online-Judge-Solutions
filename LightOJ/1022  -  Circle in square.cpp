#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	int test, i;
	double rad, ar1, ar2;
	double pi = 2 * acos(0.0);
	cin >> test;

	for (i = 1; i <= test; i++)
	{
		cin >> rad;
		ar1 = rad*rad * 4;
		ar2 = pi*rad*rad;
		cout <<"Case "<<i<<": "<< std::fixed << std::setprecision(2) << ar1 - ar2 << endl;
	}


	return 0;
}