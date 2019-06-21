#include<bits/stdc++.h>
using namespace std;

const int maxn = 202;

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

vector <int> adj[maxn*maxn];
bool vis[maxn*maxn];
int Left[maxn*maxn], Right[maxn*maxn];

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

int match(int n)
{

    int i, ret = 0;
    bool done;

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    do
    {
        done = true;

        memset(vis, 0, sizeof(vis));

        for(i=0; i<=n; i++)
        {
            if(Left[i]==-1 && dfs(i))
            {
                done = false;
            }
        }
    }
    while(!done);

    for(i=0; i<=n; i++) ret += (Left[i]!=-1);

   // for(int i = 0; i<n; i++) if(Left[i] != -1) cout<<i<<endl;
    return ret;
}
bool grid[maxn][maxn];

bool valid(int i, int j, int n, int m){

    if(i<=0 || i>n || j<=0 || j>m || grid[i][j] == 1) return false;
    return true;
}

int main()
{



    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n, m, kk;

        scanf("%d %d %d", &n, &m, &kk);

        for(int i = 0; i<maxn*maxn; i++) adj[i].clear();

        memset(grid, 0, sizeof(grid));

        for(int i = 0; i<kk; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            grid[x][y] = 1;
        }


        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){

                if((i+j)%2 == 1){

                    if(grid[i][j]==0){

                            for(int k = 0; k<8; k++){

                                if(valid(i + dx[k], j + dy[k], n, m)){

                                    int from = (i-1)*m + j;
                                    int to = (i+dx[k]-1)*m + j + dy[k];

                                    adj[from].push_back(to);

                                 //   cout<<from<<" "<<to<<endl;
                                }

                            }

                    }

                }
            }
        }

        int tot = n*m - kk;

        int res = match(n*m);

        printf("Case %d: %d\n", ++cs, tot-res);

    }




}

