#include<bits/stdc++.h>
using namespace std;

string s;

void solve(){
    int ret = 0;
    stack<char> st;

    for(int i = 0; i<s.size(); i++){
        if(s[i]=='{') st.push('{');
        else{
            if(st.size()==0){
                st.push('{');
                ++ret;
            }
            else{
                st.pop();
            }
        }
    }
    int tm = st.size();
    ret += tm/2;

    cout<<ret<<endl;
}

int main() {

    #ifdef local
          freopen("in.txt", "r", stdin);
    #endif

    int cs = 0;
    while(cin>>s){
        if(s[0]=='-') break;
        printf("%d. ", ++cs);
        solve();
    }  

}

