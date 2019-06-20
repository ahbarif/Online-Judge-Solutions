#include<bits/stdc++.h>
using namespace std;

const int maxn = 345;
map<long long, int> mp;
string ar[maxn];
vector<int> adj[maxn];
bool in[maxn];
long long base = 97, mod = 1000000007;

char str1[1000005], str2[1000005];

long long Hash(const char *str)
{

    int len = strlen(str);

    long long p = base;

    long long forwardHash = p * str[0];

    for(int i = 1; i<len; i++)
    {
        p = (p*base)%mod;
        long long tmp = p * str[i];
        forwardHash += tmp;
        forwardHash %= mod;
    }
    return forwardHash;
}

void dfs(int u)
{
    printf("%s\n", ar[u].c_str());

    for(int i = 0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        dfs(v);
    }
}
void solve()
{
    mp.clear();
    for(int i = 0; i<maxn; i++) adj[i].clear(), in[i] = true;

    int n, tick = 1;
    scanf("%d", &n);

    for(int i = 1; i<n; i++)
    {

        scanf("%s %s", str1, str2);

        long long u = Hash(str1);
        long long v = Hash(str2);

        string ss = str1, pp = str2;
        int uu, vv;

        if(mp[u] == 0) ar[tick] = ss, mp[u] = tick, tick++;
        if(mp[v] == 0) ar[tick] = pp, mp[v] = tick, tick++;

        uu = mp[u];
        vv = mp[v];

        adj[uu].push_back(vv);
        in[vv] = false;

    }

    int root;

    for(root = 1; root<tick; root++)
    {
        if(in[root] == true)
        {
            break;
        }
    }

    dfs(root);

}
int main()
{
   //  freopen("in.txt", "r", stdin);


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        printf("Case %d:\n", ++cs);
        solve();
        puts("");
    }

    return 0;
}



