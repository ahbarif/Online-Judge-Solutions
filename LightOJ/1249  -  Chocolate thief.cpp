#include<bits/stdc++.h>
using namespace std;
int main(){
 
    vector<pair<int, string> > a;
    int t, i, j, x, y, z, n;
    string s;
 
    cin>>t;
    for(i=0; i<t; i++){
        cin>>n;
        for(j=0; j<n; j++){
        cin>>s>>x>>y>>z;
 00
        a.push_back(pair<int, string> (x*y*z, s));
        }
        sort(a.begin(), a.end());
 
        if(a[0].first==a.back().first)  printf("Case %d: no thief\n", i+1);
        else cout<<"Case "<<i+1<<": "<<a.back().second<<" took chocolate from "<<a[0].second<<endl;
        a.clear();
 
    }
 
return 0;
 
}
 