#include<bits/stdc++.h>
using namespace std;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
int n, m, dis_jane[202][202], dis_fire[202][202];
 
char grid[202][202];
 
int flag, st, en;
 
bool valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
 
bool escape(int i, int j)
{
    return (i==0 || i==n-1 || j==0 || j==m-1);
}
 
void fire_spread()
{
        memset(dis_fire, -1, sizeof(dis_fire));
 
        queue<pair<int, int> > q;
 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='J') st = i, en = j;
 
                else if(grid[i][j]=='F')
                {
                    dis_fire[i][j] = 0;
                    q.push(make_pair(i, j));
 
                }
                else if(grid[i][j]=='#')    dis_fire[i][j] = 0;
            }
        }
 
        while(!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
 
            for(int i=0; i<4; i++)
            {
                int x = top.first + dx[i];
                int y = top.second + dy[i];
 
                if(valid(x, y))
                {
                    if(dis_fire[x][y]==-1)
                    {
                        dis_fire[x][y] = 1 + dis_fire[top.first][top.second];
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
 
}
 
void bfs()
{
        memset(dis_jane, -1, sizeof(dis_jane));
 
        dis_jane[st][en] = 0;
 
        if(escape(st, en))
        {
            flag = 0;
            return;
        }
 
        queue<pair<int, int> > q;
        q.push(make_pair(st, en));
 
        while(!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
 
            for(int i=0; i<4; i++)
            {
                int x = top.first + dx[i];
                int y = top.second + dy[i];
 
                if(valid(x, y))
                {
                    if(dis_jane[x][y]==-1)
                    {
                        if((1+dis_jane[top.first][top.second]<dis_fire[x][y]) || dis_fire[x][y]==-1)
                        {
                            dis_jane[x][y] = 1 + dis_jane[top.first][top.second];
 
                            q.push(make_pair(x, y));
 
                            flag = (escape(x, y)?min(flag, dis_jane[x][y]):flag);
                        }
                    }
                }
            }
        }
 
}
 
int main()
{
        int test, cs = 0, i, j;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
                scanf("%d %d", &n, &m);
 
                for(i=0; i<n; i++)  scanf("%s", grid[i]);
 
                flag = INT_MAX;
 
                fire_spread();
 
                bfs();
 
                printf("Case %d: ", ++cs);
 
                if(flag==INT_MAX) puts("IMPOSSIBLE");
 
                else printf("%d\n", 1 + flag);
 
        }
 
        return 0;
 
}
