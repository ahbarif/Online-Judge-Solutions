#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int maxn = 30, inf = 16843009;

char grid[maxn][maxn];
bool vis[maxn*maxn];
int dis[maxn][maxn], n;
vector<int> adj[maxn*maxn];
vector<pair<int, int> > ghosts, humans;
int matrix[55][55], Left[maxn*maxn], Right[maxn*maxn];

int mark(int i, int j) {
    return i*n + j;
}

void init(){
    memset(vis, 0, sizeof(vis));
    memset(matrix, 1, sizeof(matrix));
    ghosts.clear();
    humans.clear();
}

void addEdge(int i, int j){

    j += ghosts.size();
 //   cout<<i<<" -> "<<j<<endl;
    adj[i].push_back(j);
}

void bfs(int gh){

    memset(dis, -1, sizeof(dis));
    dis[ghosts[gh].first][ghosts[gh].second] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(ghosts[gh].first, ghosts[gh].second));

    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int tx = top.first + dx[i];
            int ty = top.second + dy[i];

            if(tx>=0 && ty>=0 && tx<n && ty<n && grid[tx][ty] != '#' && dis[tx][ty] == -1){
                dis[tx][ty] = 1 + dis[top.first][top.second];
                q.push(make_pair(tx, ty));
            }
        }
    }

    for(int j = 0; j<humans.size(); j++){
        if(dis[humans[j].first][humans[j].second] != -1){
          //  cout<<"dis = "<<dis[humans[j].first][humans[j].second]<<endl;
            matrix[gh][j] = dis[humans[j].first][humans[j].second];

        }
    }
}

void createGraph(int mid){
    for(int i = 0; i<maxn*maxn; i++) adj[i].clear();
    for(int i = 0; i<ghosts.size(); i++){
        for(int j = 0; j<humans.size(); j++){
            int needed = matrix[i][j]*2 + 2;
            if(needed<=mid) addEdge(i, j);

        }
    }
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

int maxMatch(int n){
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

int binarySearch(){

    int lo = 2, mid, hi = 2000, res = inf;

    for(int j = 0; j<30; j++){
        mid = (lo+hi)/2;
        createGraph(mid);

        if(maxMatch(ghosts.size()+humans.size()) == humans.size()){
            hi = mid;
            res = min(res, mid);
        }
        else lo = mid+1;
    }

    return res;
}

void solve(int cs){
   init();

   cin>>n;

   for(int i = 0; i<n; i++) scanf("%s", grid[i]);

   for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
        if(grid[i][j] == 'G') ghosts.push_back(make_pair(i, j));
        if(grid[i][j] == 'H') humans.push_back(make_pair(i, j));

    }
   }

   for(int i = 0; i<ghosts.size(); i++) bfs(i);
//
//   for(int i = 0; i<ghosts.size(); i++){
//    for(int j = 0; j<humans.size(); j++){
//       if(matrix[i][j]==inf) printf(". ");
//       else cout<<matrix[i][j]<<" ";
//    }
//    puts("");
//   }

   int ret = binarySearch();

   if(ret == inf) printf("Case %d: Vuter Dol Kupokat\n", cs);
   else printf("Case %d: %d\n", cs, ret);

}

int main()
{
  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;
    for(scanf("%d", &test); test ; --test) solve(++cs);
    return 0;

}


