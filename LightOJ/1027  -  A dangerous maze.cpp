#include<bits/stdc++.h>
using namespace std;

int ___gcd(int a, int b)
{
    return (a%b?___gcd(b, a%b):b);
}
int main()
{

    int test, cs = 1;

    scanf("%d", &test);

    while(test--)
    {
        int n, x = 0, gcd, sum = 0;

        scanf("%d", &n);

        while(n--)
        {
            int tmp;
            scanf("%d", &tmp);

            if(tmp>0)   x++;

            sum = sum + abs(tmp);
        }
        if(x==0)    printf("Case %d: inf\n", cs++);

        else
        {
            gcd = ___gcd(sum, x);

            sum/=gcd;
            x/=gcd;

            printf("Case %d: %d/%d\n", cs++, sum, x);

        }

    }

    return 0;

}
