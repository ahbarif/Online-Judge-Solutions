#include<bits/stdc++.h>
using namespace std;
int main()
{
   int test, n, i, a[105], tc=0, ans;
   int flag=0;
 
   scanf("%d", &test);
 
   while(test--){
 
        scanf("%d", &n);
        ans=0;
        for(i=1; i<=n; i++) scanf("%d", &a[i]);
 
        while(true){
            flag=1;
             for(i=1; i<=n; i++){
                    if(a[i]!=i) {
                        flag=0; break;
                        }
                    }
                if(!flag){
                for(i=1; i<=n; i++){
                    if(a[i]!=i) swap(a[i], a[a[i]]), ans++;
                }
            }
                else break;
        }
 
        printf("Case %d: %d\n", ++tc, ans);
 
   }
 return 0;
}