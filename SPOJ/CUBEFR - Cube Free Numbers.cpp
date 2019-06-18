#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok[1000005];
int pos[1000005];
const int N = 1000000;
void sieve(){
     for(int i = 2; i<=105; i++){
        int cube = i*i*i;
         for(int j = cube; j<=N; j+=cube) ok[j] = true;
    }
     memset(pos, -1, sizeof(pos));
    int cnt = 1;
    for(int i = 1; i<=N; i++){
        if(ok[i]==false){
            pos[i] = cnt++;
        }
    }
}
int main(){
     sieve();
     int test, cs = 0;
     scanf("%d", &test);
     while(test--){
        int n;
        scanf("%d", &n);
         printf("Case %d: ", ++cs);
         if(pos[n] == -1) printf("Not Cube Free\n");
         else printf("%d\n", pos[n]);
    }
     return 0;
}
