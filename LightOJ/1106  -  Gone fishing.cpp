#include<bits/stdc++.h>
using namespace std;

int dp[26][200], inf = 292000;
int ar[26][200];
int dis[26], f[26], rate[26];
int path[26][200];
int n, h;

int fun(int pos, int rem){

    if(pos>n) return 0;

    if(dp[pos][rem] != -1) return dp[pos][rem];

    int last = 0, tmLast = 0;

    // case1: last stopage
    for(int i = 0; i<=rem; i++){
        int tmp = ar[pos][i];

        if(tmp>=last){
            last = tmp;
            tmLast = i;
        }
    }

    // case2: jabo

    int available = rem - dis[pos];

    for(int i = 0; i<=available; i+=1){
            int tmp = ar[pos][i] + fun(pos+1, rem-(i+dis[pos]));
            if(tmp>=last){
                last = tmp;
                tmLast = i;
            }
    }

    path[pos][rem] = tmLast;

    return dp[pos][rem] =  last;
}


vector<int> timeSpent;

void print(int pos, int rem){
    if(pos>n) return;
    timeSpent.push_back(path[pos][rem]*5);
    if(rem>=dis[pos]) print(pos+1, rem - dis[pos]-path[pos][rem]);
}

int main()
{

       int test, cs = 0;

       scanf("%d", &test);

       while(test--){


            scanf("%d %d", &n, &h);

            for(int i = 1; i<=n; i++) scanf("%d", &f[i]);
            for(int i = 1; i<=n; i++) scanf("%d", &rate[i]);
            for(int i = 1; i<n; i++)  scanf("%d", &dis[i]);
            dis[n] = 0;

            memset(ar, 0, sizeof(ar));
            memset(dp, -1, sizeof(dp));

            for(int i = 1; i<=n; i++){
                ar[i][0] = 0LL;
                int init = f[i];
                for(int j = 1; j<200; j++){
                    ar[i][j] = init;
                    init -= rate[i];
                    if(ar[i][j] < 0){
                        ar[i][j] = 0;
                        break;
                    }
                }

                for(int j = 1; j<200; j++){
                    ar[i][j] += ar[i][j-1];
                }
            }

            int ret = fun(1, h*12);
            print(1, h*12);
            while(timeSpent.size()<n) timeSpent.push_back(0);

            printf("Case %d:\n", ++cs);

            for(int i = 0; i<timeSpent.size(); i++){
                if(i) printf(", ");
                printf("%d", timeSpent[i]);
            }
            printf("\nNumber of fish expected: %d\n", ret);
            timeSpent.clear();
       }

       return 0;
}
