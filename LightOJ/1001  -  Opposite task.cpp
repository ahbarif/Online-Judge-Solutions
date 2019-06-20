#include<iostream>
using namespace std;
int main()
{
	int i, test, num;
	
	cin >> test;
	for (i = 1; i <= test; i++)
	{
		cin >> num;
		if (num > 10)
		{
			cout << 10 << " " << num - 10 << endl;;
		}
		else
		{
			cout << num << " " << 0 << endl;
		}


	}

	return 0;
}