# include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LLU;

LLU nCr(int n, int r)
{
    if(r>n/2)   r=n-r;
    if(n==r)    return 1;
    if(r==0)    return 1;

    else if(r==1)   return n;

    LLU k= nCr(n-1, r), p=nCr(n-1, r-1);

    return k+p;

}

LLU nPr(int a, int b)
{
    LLU ans=1;
    int c=0;

    for(int i=a; i>0; i--)
    {
        ans*=i;
        c++;
        if(c==b)    break;
    }

    return ans;

}

int main()
{

        int n, r, test, i;
        LLU ans, s, k;

        scanf("%d", &test);

        for(i=1; i<=test; i++)
        {
            scanf("%d %d", &n, &r);
            if(r==0)    ans=1;
            else if(r>n) ans=0;
            else{

                s=nPr(n, r);

                k=nCr(n, r);

                ans=s*k;
            }

        printf("Case %d: %llu\n", i, ans);

        }


   return 0;
}

