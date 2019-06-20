#include<bits/stdc++.h>
using namespace std;
 
map<string, bool> vis;
map<string, int> dis;
 
int bfs(string src, string dst)
{
    dis.clear();
 
    if(vis[src] == true || vis[dst] == true)    return -1;
 
    if(src == dst)
    {
        return 0;
    }
 
    vis[src] = 1;
    dis[src] = 0;
 
    queue<string> q;
 
    q.push(src);
 
    while(!q.empty())
    {
        string top = q.front();
 
        q.pop();
 
        if(top==dst)    return dis[top];
 
        for(int i=0; i<3; i++)
        {
            string s = top;
 
            s[i]++;
            if(s[i]>'z') s[i] = 'a';
 
            string ss = top;
            ss[i]--;
            if(ss[i]<'a') ss[i] = 'z';
 
            if(vis[s]==0)
            {
                vis[s] = 1;
                q.push(s);
                dis[s] = dis[top] + 1;
            }
 
 
            if(vis[ss]==0)
            {
                vis[ss] = 1;
                q.push(ss);
                dis[ss] = dis[top] + 1;
            }
        }
    }
 
    return -1;
}
 
int main()
{
 
        int test, cs = 0;
 
        scanf("%d", &test);
 
        while(test--)
        {
            vis.clear();
 
            string source, dest, temp;
 
            int n, i, j, k;
 
            cin >> source >> dest;
 
            scanf("%d", &n);
 
            while(n--)
            {
                string x, y, z;
 
                cin>> x >> y >> z;
 
                int size_1 = x.size();
                int size_2 = y.size();
                int size_3 = z.size();
 
                for(i=0; i<size_1; i++)
                {
                    for(j=0; j<size_2; j++)
                    {
                        for(k=0; k<size_3; k++)
                        {
                            temp = "...";
                            temp[0] = x[i];
                            temp[1] = y[j];
                            temp[2] = z[k];
 
                            vis[temp] = true;
                        }
                    }
                }
 
 
            }
 
            printf("Case %d: %d\n", ++cs, bfs(source, dest));
 
        }
 
        return 0;
}
 