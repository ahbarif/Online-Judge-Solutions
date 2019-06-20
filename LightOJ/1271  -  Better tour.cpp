#include<bits/stdc++.h>
using namespace std;
 
const int mx = 50005;
 
vector<int> g[mx];
int par[mx];
int arr[mx];
 
void init()
{
    for(int i = 0; i<mx; i++)   g[i].clear();
    memset(par, 0, sizeof(par));
}
 
void bfs(int src, int dst)
{
    par[src] = -1;
 
    queue<int> q;
 
    q.push(src);
 
    while(!q.empty())
    {
        int top = q.front();
 
        q.pop();
 
        if(top==dst)    return;
 
        int sz = g[top].size();
 
        for(int i=0; i<sz; i++)
        {
            int u = g[top][i];
 
            if(par[u]==0)
            {
                par[u] = top;
                q.push(u);
            }
        }
    }
}
 
void print_path(int src, int dst)
{
    vector<int> v;
 
    while(dst!=-1)
    {
        v.push_back(dst);
 
        dst = par[dst];
 
        if(dst==src)
        {
            v.push_back(dst);
            break;
        }
    }
 
    for(int i=v.size()-1; i>0; i--)   printf("%d ", v[i]);
 
    printf("%d\n", v[0]);
}
 
int main()
{
 
        int test, cs = 0;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
            init();
 
            int n, i;
 
            scanf("%d", &n);
 
            for(i=0; i<n; i++)
            {
                scanf("%d", &arr[i]);
            }
 
            for(i=0; i<n-1; i++)
            {
                g[arr[i]].push_back(arr[i+1]);
                g[arr[i+1]].push_back(arr[i]);
            }
 
            for(i=0; i<mx; i++) sort(g[i].begin(), g[i].end());
 
            printf("Case %d:\n", ++cs);
 
            bfs(arr[0], arr[n-1]);
 
            print_path(arr[0], arr[n-1]);
 
        }
 
        return 0;
}
 