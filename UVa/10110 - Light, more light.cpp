#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, a;

    while(cin>>n){
        if(n==0)break;
        a=sqrt(n);
        if(n==a*a)  puts("yes");
        else puts("no");
    }

    return 0;
}
