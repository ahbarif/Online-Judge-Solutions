#include<bits/stdc++.h>
using namespace std;

int main(){

   long long a[22]={1}, n;

   int i, top, tc, x, k;

   vector<int> ans;

   for(i=1; i<20; i++)  a[i]=i*a[i-1];

    scanf("%d", &tc);
    k=1;

    for(x=1; x<=tc; x++){

        scanf("%lld", &n);

        for(i=19; i>=0; i--){
            if(a[i]<=n) {
                ans.push_back(i);
                n-=a[i];
                if(n==0) {k=1; break;}
            }
        }

        if(n!=0)  k=0;

        if(k==0)    cout<<"Case "<<x<<": impossible\n";
        else {
            sort(ans.begin(), ans.end());
            cout<<"Case "<<x<<": ";
            for(i=0; i<ans.size()-1; i++) cout<<ans[i]<<"!+";
            cout<<ans.back()<<"!"<<endl;
        }
        ans.clear();
    }

    return 0;
}