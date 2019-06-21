#include <bits/stdc++.h>
using namespace std;

struct people{
    int height, age, type;
};

const int maxn = 1005;

vector <int> adj[maxn];
bool vis[maxn];
int Left[maxn], Right[maxn];

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


int maxMatch(int n)
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

people man[55], woman[55];

bool ok(people arif, people anika){

    if(abs(arif.height - anika.height)<=12 && abs(arif.age-anika.age)<=5 && arif.type == anika.type) return true;
    return false;

}

int main()
{

        int test, cs = 0;

        cin>>test;

        while(test--){


            for(int i = 0; i<maxn; i++) adj[i].clear();

            int n, m;

            scanf("%d %d", &n, &m);

            for(int i = 0; i<n; i++) scanf("%d %d %d", &man[i].height, &man[i].age, &man[i].type);
            for(int i = 0; i<m; i++) scanf("%d %d %d", &woman[i].height, &woman[i].age, &woman[i].type);

            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){

                    if(ok(man[i], woman[j])){
                        adj[i].push_back(j);
                    }
                }
            }


            printf("Case %d: %d\n", ++cs, maxMatch(n+m));

        }

	return 0;
}

