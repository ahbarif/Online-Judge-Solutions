#include<bits/stdc++.h>
using namespace std;

bool isSquare(long long n)
{
    long long root = sqrt(n);
    return root*root==n;
}

long long H(long long n)
{

    long long pre = n, res = 0, root = sqrt(n), cur, i;

    for(i = 1; i<=root; i++)
    {
        cur = n/i;

        res += (pre - cur)*(i-1);

        res+=cur;

        pre = cur;

    }

    if(isSquare(n+1))   res = res+root;

    return (root<pre?res+root:res);

}


int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        long long n;

        scanf("%lld", &n);

        printf("Case %d: %lld\n", ++cs, H(n));
    }

    return 0;


}
