#include<bits/stdc++.h>
using namespace std;

int a[100005], n;
bool flag[1425];

void init(){

    memset(flag, 0, sizeof(flag));

    for(int i = 1; i<=n; i++){
         cin>>a[i];
         flag[a[i]] = 1;
    }

    sort(a+1, a+n+1);

    int cur = 0, dest = 1422;
    int cap = 200;

    while(cur < dest){
        if(flag[cur]) cap = 200;
        if(cap == 0) break;
        cap--;
        cur++;
    }

    if(cur != dest) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    if(flag[dest]) cap = 200;

    while(cur>0){
        if(flag[cur]) cap = 200;
        if(cap == 0) break;
        cap--;
        cur--;
    }

    if(cur != 0) cout<<"IMPOSSIBLE"<<endl;
    else cout<<"POSSIBLE"<<endl;

}

int main() {

    #ifdef local
     //   freopen("in.txt", "r", stdin);
    #endif

    while(cin>>n && n){
        init();
    }

}
