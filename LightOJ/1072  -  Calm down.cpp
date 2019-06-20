#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int main()
{
   // freopen("out.txt","w",stdout);
    int i, test;
    double Rad, r, value, tra, n;
    cin >> test;
 
    for (i = 1; i <= test; i++)
    {
        cin >> Rad >> n;
 
        if (n == 2)
        {
            cout << "Case " << i << ": " << Rad / 2 << endl;
        } else {
        value = 180 / n;
 
        tra = sin(value*pi/ 180);
 
        r = (Rad*tra) / (1 + tra);
 
        cout <<"Case "<<i<<": "<<std::fixed<<std::setprecision(6)<< r << endl;
        }
    }
 
    return 0;
 
}
 