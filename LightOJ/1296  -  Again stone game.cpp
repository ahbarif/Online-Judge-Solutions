#include <bits/stdc++.h>
using namespace std;

int grundy(int x)
{
    if(x==1)    return 0;
    if(x%2==0)  return x/2;
    else return grundy(x/2);
}

int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
            int n, sum = 0, x;

            scanf("%d", &n);

            while(n--)
            {
                scanf("%d", &x);
                sum^=grundy(x);
            }

            printf("Case %d: ", ++cs);

            puts(!sum?"Bob":"Alice");
    }

    return 0;
}


