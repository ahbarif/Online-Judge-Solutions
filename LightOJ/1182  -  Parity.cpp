#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	long long int num, mod, count, i, test;

	cin >> test;
	for (i = 1; i <= test; i++)
	{
		count = 0;
		cin >> num;

		while (num > 0)
		{
			mod = num % 2;
			num = num / 2;
			if (mod % 2 == 1)
			{
				count++;
			}

		}
		
		if (count % 2 == 0)
		{
			cout << "Case " << i << ": even" << endl;
		}
		else
		{
			cout << "Case " << i << ": odd" << endl;
		}

	}
	return 0;
}