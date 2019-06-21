#include<bits/stdc++.h>
using namespace std;

int64_t myfunc(int64_t n){

    int64_t res = 0;

    for(int64_t i = 2; i*i<=n; i++){

        int64_t j = n/i;

        int64_t tmp1 = (i+j)*(j-i+1)/2;
        int64_t tmp2 = i*(j-i);
        res += tmp1;
        res += tmp2;

    }

    int64_t ex = (n*(n+1))/2;

    return res+ex+n-2;
}
int main()
{

    int64_t n;

    while(cin>>n && n){
        cout<<myfunc(n)<<endl;
    }

    return 0;
}
