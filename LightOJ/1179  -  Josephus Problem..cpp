# include<bits/stdc++.h>
using namespace std;

int g(int n, int k)
{
        if(n==0)        return 1;
        return (g(n-1, k)+k)%n;
}

int main()
{
       int test, caseno=0;

       cin>>test;
       while(test--)
       {
           int n, k;
           scanf("%d %d", &n, &k);
           int ans=g(n, k);

           printf("Case %d: %d\n", ++caseno, ++ans);
       }


   return 0;
}
