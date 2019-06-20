#include<bits/stdc++.h>
using namespace std;
 
vector<int> g[105];
int adj[105][105];
bool flag[105];
void init()
{
    for(int i=0; i<105; i++)    g[i].clear();
 
    memset(adj, -1, sizeof(adj));
 
    memset(flag, 0, sizeof(flag));
 
    flag[1] = 1;
}
 
int cost(vector<int> v)
{
 
    int sum1 = 0, sum2 = 0;
 
    for(int i=0; i<v.size()-1; i++)
    {
        int x = v[i];
        int y = v[i+1];
        if(adj[x][y]==-1)   sum1+=adj[y][x];
    }
 
    reverse(v.begin(), v.end());
 
    for(int i=0; i<v.size()-1; i++)
    {
        int x = v[i];
        int y = v[i+1];
        if(adj[x][y]==-1)   sum2+=adj[y][x];
    }
 
    return min(sum1, sum2);
 
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        vector<int> v;
 
        int n, i, x, y, z;
 
        scanf("%d", &n);
 
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
 
            adj[x][y] = z;
 
            g[x].push_back(y);
 
            g[y].push_back(x);
        }
 
 
        int cnt = n-1;
 
        v.push_back(1);
 
        while(cnt--)
        {
            int last = v.back();
 
            if(flag[g[last][0]] == 0)
            {
                v.push_back(g[last][0]);
                flag[g[last][0]] = 1;
 
            }
 
            else if(flag[g[last][1]] == 0)
            {
                v.push_back(g[last][1]);
                flag[g[last][1]] = 1;
            }
        }
 
        v.push_back(1);
 
        int res = cost(v);
 
        printf("Case %d: %d\n", ++cs, res);
    }
 
    return 0;
}
 

VOLUME
Volume Home
Problem Set
Problem Category
Problem Setters
Submit Problem
My Submissions
Judge Status
Ranklist
User Statistics
Compare User Statistics
 
Developed and Maintained by 
JANE ALAM JAN