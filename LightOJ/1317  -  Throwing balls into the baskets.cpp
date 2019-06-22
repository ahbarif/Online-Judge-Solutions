#include<bits/stdc++.h>
using namespace std;
 
int main ()
{
 
  //  freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--){
 
        double a, b, c, d;

        cin>>a>>b>>c>>d;

        double res = a*c*d;

        printf("Case %d: %.10lf\n", ++cs, res);
 
    }
 
 
    return 0;
}
