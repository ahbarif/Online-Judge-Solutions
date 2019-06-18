#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
vector<int> pos[maxn];
int a[20*maxn];
int main () {
#ifdef local
         freopen("in.txt", "r", stdin);
#endif // local
         int n, c, q;
         scanf("%d %d", &n, &c);
         for(int i = 1; i<=n; i++) {
                scanf("%d", &a[i]);
                 pos[a[i]].push_back(i);
        }
         scanf("%d", &q);
         while(q--){
            int lo, hi;
             scanf("%d %d", &lo, &hi);
             bool flag = false;
             for(int j = 0; j<20; j++){
                int p = lo + rand()%(hi-lo+1);
                int x = a[p];
                 int occ = (hi-lo+1)/2;
                 int freq = upper_bound(pos[x].begin(), pos[x].end(), hi) - lower_bound(pos[x].begin(), pos[x].end(), lo);
                 if(freq > occ){
                    printf("yes %d\n", x);
                    flag = true;
                    break;
                }
            }
             if(!flag) puts("no");
          }
      return 0;
}
