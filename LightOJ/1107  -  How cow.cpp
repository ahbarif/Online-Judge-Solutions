#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	
	int x1, x2, y1, y2, test_ins, test_out, i=0, j, a, b;
	cin >> test_out;

	for (j = 1; j <= test_out; j++)
		
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> test_ins;
		cout << "Case " << j << ":" << endl;
		for (i = 1; i <= test_ins; i++)
		{
			cin >> a >> b;
			if (a > x1 && a < x2 && b > y1 && b < y2)
			{
				cout << "Yes" << endl;

			}
			else
			{
				cout << "No" << endl;
			}
		}

	}


	return 0;
}