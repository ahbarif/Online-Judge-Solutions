#include<bits/stdc++.h>
using namespace std;
 
const int sz = 10000010;
 
bool mark[sz];
 
void sieve()
{
    mark[1] = true;
 
    for (int i=4; i<sz; i+=2)    mark[i] = true;
 
    for (int p=3; p<=sz; p+=2)
    {
        if (mark[p] == false)
        {
            for (int i = 2*p; i<sz; i += p)
            {
                mark[i] = true;
            }
        }
    }
}
 
int main()
{
    sieve();
 
    int test, cs = 0;
 
    cin>>test;
 
    while(test--)
    {
        int n, x;
 
        long long sum = 0;
 
        scanf("%d", &n);
 
        while(n--)
        {
            scanf("%d", &x);
 
            for(int j = x+1; ; j++)
            {
                if(mark[j] == 0)
                {
                    sum = sum + j;
                    break;
                }
            }
        }
 
        printf("Case %d: %lld Xukha\n", ++cs, sum);
 
    }
 
    return 0;
}
