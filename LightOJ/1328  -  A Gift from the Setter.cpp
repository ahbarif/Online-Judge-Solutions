#include<bits/stdc++.h>
using namespace std;
 
typedef long long i64;
 
i64 prefixSum[100005];
 
i64 a[100005];
 
long long GetDiffSum( i64 a[], int n )
{
    long long sum = 0;
    int i, j;
    for( i = 0; i < n; i++ )
        for( j = i + 1; j < n; j++ )
        {
          //  printf("abs(%d - %d)\n", i, j);
            sum += abs( a[i] - a[j] );
        }
 
    return sum;
}
 
i64 getSum(int lo, int hi)
{
    return prefixSum[hi] - prefixSum[lo-1];
}
 
 
 
int main()
{
 
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        i64 k, c, n;
 
        scanf("%lld %lld %lld", &k, &c, &n);
 
        scanf("%lld", &a[0]);
 
        for(int i = 1; i<n; i++)
        {
            a[i] = (k*a[i-1] + c)% 1000007;
        }
 
        sort(a, a+n, std::greater<int>());
 
        prefixSum[0] = a[0];
 
        for(int i = 1; i<n; i++) prefixSum[i] = a[i] + prefixSum[i-1];
 
        i64 res = 0;
 
        for(int i = 0; i<n-1; i++)
        {
            int lo = i+1, hi = n-1;
            int val = hi-lo+1;
            i64 tmp = a[i]*val - getSum(lo, hi);
            res += tmp;
 
        }
 
        cout<<"Case "<<++cs<<": "<<res<<endl;
      //  cout<<res<<endl;
       // cout<<GetDiffSum(a, n)<<endl;
 
 
 
    }
 
    return 0;
 
}
