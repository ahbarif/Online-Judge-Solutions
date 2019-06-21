/*
    Algorithm: Edmond - Karp Max flow
*/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int inf = 100000;
const int source = 0;
const int sink = 57;

int cap[maxn][maxn], par[maxn], mcap[maxn];

vector<int> adj[maxn];

int getId(string s){

    if(s=="XS") return 51;
    if(s=="S") return 52;
    if(s=="M") return 53;
    if(s=="L") return 54;
    if(s=="XL") return 55;
    if(s=="XXL") return 56;

}

void init(){
    for(int i = 0; i<maxn; i++) adj[i].clear();
    memset(cap, 0, sizeof(cap));
}

bool getpath(int s, int d, int n)
{
    memset(par, -1, sizeof(par));

    for(int i=0;i<=n;i++) mcap[i]=inf;

    queue<int> q;

    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<=n;i++)
        {
            if(cap[u][i]!=0 && par[i]==-1)
            {
                par[i]=u;
                mcap[i]=min(mcap[u],cap[u][i]);
                if(i==d) return true;
                q.push(i);
            }
        }
    }

    return false;
}

int getflow(int s,int d,int n)
{
    int F=0;
    while(getpath(s,d,n))
    {

        int f=mcap[d];
        F+=f;
        int u=d;
        while(u!=s)
        {
            int v=par[u];
            cap[u][v]+=f;
            cap[v][u]-=f;
            u=v;
        }
    }
    return F;
}

void solve(int cs){

        init();

        int n, m;

        scanf("%d %d", &n, &m);

        for(int i = 1; i<=m; i++){

            string x1, x2;

            cin>>x1>>x2;

            int v1 = getId(x1);
            int v2 = getId(x2);

            cap[i][v1] += 1;
            cap[v1][i] += 1;

            cap[i][v2] += 1;
            cap[v2][i] += 1;
        }



        for(int i = 1; i<=50; i++){

            cap[i][source] += 1;
            cap[source][i] += 1;
        }

        for(int i = 51; i<=56; i++){

            cap[i][sink] += n;
            cap[sink][i] += n;
        }

        int res = getflow(0, 57, 57);
    

        printf("Case %d: ", cs);
        
        puts(res==m?"YES":"NO");

}

int main()
{
        int test, cs = 0;

        scanf("%d", &test);

        while(test--){

           solve(++cs);
        }
}

