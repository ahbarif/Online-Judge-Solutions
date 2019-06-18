#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int a[200005];
bool cmp(pair<int, int> a, pair<int, int> b){
    return (a.second-a.first)<(b.second-b.first);
}
ll solve(int l, int r){
//  cout<<l<<" "<<r<<endl;
    if(r==l+1) return 2;
     int x, y, mxx = 0;
     vector<pair<int, int> > v;
     for(int i = l+1; i<r; i++){
        if(s[i]=='['){
            int rr = a[i];
            int ll = i;
             int dif = rr-ll;
             if(dif>mxx){
                mxx = dif;
                x = ll;
                y = rr;
            }
        }
    }
     return 2LL*solve(x, y);
 }
int main()
{
     int test, cs = 0;
    cin>>test;
    cin.ignore();
     while(test--){
        cout<<++cs<<" ";
        getline(cin, s);
        if(s=="") {
            cout<<1<<endl;
            continue;
        }
         memset(a, -1, sizeof(a));
         stack<int> st;
         for(int i = 0; i<s.size(); i++)
        {
             if(s[i]=='[') st.push(i);
            else{
                int top = st.top();
                st.pop();
                a[top] = i;
            }
        }
          cout<<solve(0, s.size()-1)<<endl;
     }
