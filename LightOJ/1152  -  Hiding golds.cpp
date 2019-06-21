#include<bits/stdc++.h>
using namespace std;

const int maxn = 25;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector <int> adj[maxn*maxn];
bool vis[maxn*maxn];
int Left[maxn*maxn], Right[maxn*maxn];
int mark[25][25];

int node_number(int i, int j){

    return mark[i][j];

}

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

   // for(int i = 0; i<n; i++) if(Left[i] != -1) cout<<i<<endl;
    return ret;
}

char grid[25][25];


bool valid(int i, int j, int n, int m){

    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != '*') return false;
    return true;
}

void pre(int n, int m){
    int toto = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            mark[i][j] = toto++;
        }
    }
}
int main()
{



 //   freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        int n, m;

        scanf("%d %d", &n, &m);

    pre(n, m);

        for(int i = 0; i<n; i++) scanf("%s", grid[i]);

        for(int i = 0; i<maxn*maxn; i++) adj[i].clear();

        int tot = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(grid[i][j]=='*') tot++;

                if((i+j)%2){
                    if(grid[i][j]=='*'){

                            for(int k = 0; k<4; k++){
                                if(valid(i + dx[k], j + dy[k], n, m)){
                                 //   cout<<node_number(i, j)<<" "<<node_number(i+dx[k], j + dy[k])<<endl;

                                  adj[node_number(i, j)].push_back(node_number(i+dx[k], j + dy[k]));
                                }

                            }

                    }

                }
            }
        }

        int res = tot - match(n*m);

        printf("Case %d: %d\n", ++cs, res);



    }




}

