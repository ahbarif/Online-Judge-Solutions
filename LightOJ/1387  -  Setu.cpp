#include<bits/stdc++.h>
using namespace std;
int main(){


    int t, s, i, j, x, z;
    string a;
    cin>>t;
    for(i=1; i<=t; i++){
        s=0;
        cin>>z;
        cout<<"Case "<<":\n";
        for(j=0; j<z; j++){
            cin>>a;
            if(a=="donate"){
             cin>>x;
             s+=x;
            }
            else cout<<s<<endl;
        }
    }





}
