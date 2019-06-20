#include<bits/stdc++.h>
using namespace std;

bool ok(long long n, long long a)
{
    long long b = a/10;
    return (n == a-b);
}

int main()
{

        int test;

        cin>>test;

        for(int i=1; i<=test; i++)
        {
            long long n;
            long long b = -1;

            cin>>n;

            long long a = (n)/9;
            a+=n;
            if(ok(n, a+1)) b = a+1;
            else if(ok(n, a-1))    b = a-1;


            if(b==-1)   cout<<"Case "<<i<<": "<<a<<endl;

            else
            {
                if(a>b) swap(a, b);
                cout<<"Case "<<i<<": "<<a<<" "<<b<<endl;
            }

        }

        return 0;

}
