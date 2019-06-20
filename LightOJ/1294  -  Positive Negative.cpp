#include<bits/stdc++.h>
using namespace std;

int main(){

    long long n, m, res, s1, s2, k, ans, test, i;

    cin>>test;

    for(i=1; i<=test; i++){

        cin>>n>>m;

        k = (m*(2*m+1)) - (m*(m+1));

        res=n/(2*m);

        ans=k*res;

        cout<<"Case "<<i<<": "<<ans<<endl;
    }


    return 0;
}