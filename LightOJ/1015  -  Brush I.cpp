#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n, a, sum = 0, j, test;
 
    cin >> test;
    for (j = 1; j <= test; j++)
    {
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a>0)
            {
                sum = sum + a;
            }
        }
        cout << "Case " << j << ": " << sum<<endl;
 
    }
 
 
 
    return 0;
}
 