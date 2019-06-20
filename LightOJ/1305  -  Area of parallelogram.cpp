#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{

	int x1, x2, x3, x4, y1, y2, y3, y4, area, i, test;
	cin >> test;

	for (i = 1; i <= test; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		x4 = x1 + (x3 - x2);
		y4 = y1 + (y3 - y2);

		area = ((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (x2*y1 + x3*y2 + x4*y3 + x1*y4)) / 2;
		if (area < 0)
		{
			area = area*(-1);
		}

		cout <<"Case "<<i<<": "<< x4 << " " << y4 << " " << area << endl;
	}

		return 0;
}