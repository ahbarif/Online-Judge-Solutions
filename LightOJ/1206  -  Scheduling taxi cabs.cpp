#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

vector <int> adj[maxn];
bool vis[maxn];
int Left[maxn], Right[maxn];

int st[maxn], fin[maxn], ax[maxn], bx[maxn], cx[maxn], dx[maxn];

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;
    int len = adj[u].size(), i, v;
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
        if(Right[v]==-1)
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
        if(dfs(Right[v]))
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int bpm(int n)
{


    int i, ret = 0;
    bool done;

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    do
    {
        done = true;

        memset(vis, 0, sizeof(vis));

        for(i=0; i<n; i++)
        {
            if(Left[i]==-1 && dfs(i))
            {
                done = false;
            }
        }
    }
    while(!done);

    for(i=0; i<n; i++) ret += (Left[i]!=-1);

    return ret;
}


int main()
{

     //   freopen("in.txt", "r", stdin);

        int test, cs = 0;

        cin>>test;

        while(test--){


            for(int i = 0; i<maxn; i++) adj[i].clear();

            int n;

            scanf("%d", &n);

            for(int i = 0; i<n; i++){
                int h, m, a, b, c, d;

                scanf("%d:%d %d %d %d %d", &h, &m, &ax[i], &bx[i], &cx[i], &dx[i]);

                st[i] = h*60+m;

                fin[i] = st[i] + abs(ax[i]-cx[i]) + abs(bx[i]-dx[i]);
            }


            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(i==j) continue;

                    int reach = fin[i] + abs(cx[i]-ax[j]) + abs(dx[i]-bx[j]);

                    if(reach < st[j]){
                        adj[i].push_back(j);
                    }
                }
            }

            printf("Case %d: %d\n", ++cs, n - bpm(n));

        }

	return 0;
}

