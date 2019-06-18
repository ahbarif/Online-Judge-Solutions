#include<bits/stdc++.h>
using namespace std;
int adj[10][10];
long long a[10];
bool ok(int mask){
for(int i = 0; i<8; i++){
if((mask&(1<<i))){
   for(int j = 0; j<8; j++){
    if((mask&(1<<j))){
     if(adj[i][j] || adj[j][i]) return 0;
    }
   }
}
 }
return 1;
}
long long getAns(int mask){
long long ret = 0;
for(int i = 0; i<8; i++){
if((mask&(1<<i))){
   ret += a[i];
}
 }
return ret;
}
int main(){
//freopen("in.txt", "r", stdin);
for(int i = 0; i<8; i++) cin>>a[i];
int m;
cin>>m;
while(m--){
int u, v;
cin>>u>>v;
u--;
v--;
adj[u][v] = 1;
adj[v][u] = 1;
}
long long int ret = 0;
for(int i = 0; i<(1<<8); i++){
if(ok(i)) ret = max(ret, getAns(i));
 }
cout<<ret<<endl;
