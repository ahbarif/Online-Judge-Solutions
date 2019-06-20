# include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[10000];

void convert(LL n)
{

    LL i, p=0, x=n, z;

    while(x)
    {
        a[p++]=x%2;
        x/=2;
    }

    z=p;
    if(n%2==1)
    {
        for(i=0; i<=p+1; i++)
        {
            if(a[i]==0 && a[i-1])
            {
                swap(a[i], a[i-1]);
                break;
            }
        }
    }

    else
    {
            int f=0;
            for(i=0; i<=p; i++)
            {
                    if(a[i])    break;
            }
            for(; i<=p; i++)
            {
                if(!a[i])   break;
            }
            i--;

            while(true)
            {
                if(a[i+1]==0)   swap(a[i], a[i+1]);
                else
                {
                    p=i; break;
                }
            }
            int r=0;
            for(i=0; i<p; i++)
            {
                if(a[i]==1)
                {
                    a[r++]=1;
                    a[i]=0;
                }
            }
    }

    LL cc=1, ans=0;
    for(i=0;i<=z+1;i++)
    {
        ans+=cc*(a[i]);
        cc<<=1;
    }
    cout<<ans<<endl;
}

int main()
{
       LL n, test, caseno=0;

       cin>>test;
       while(test--)
       {
           memset(a, 0, sizeof(a));
           cin>>n;
           cout<<"Case "<<++caseno<<": ";
           convert(n);
       }


   return 0;
}
