#include<bits/stdc++.h>
using namespace std;


int main () {

    #ifdef locala
            freopen("in.txt", "r", stdin);
    #endif

    int t, cs = 0;

    cin>>t;

    while(t--){
        int a, b, sum = 0;

        cin>>a>>b;

        for(int i = min(a, b); i<=max(a, b); i++){
            if(i&1) sum += i;
        }

        cout<<"Case "<<++cs<<": "<<sum<<endl;
    }


}
