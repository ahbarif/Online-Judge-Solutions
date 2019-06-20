#include<bits/stdc++.h>
using namespace std;
 
int dx[]= {+1, -1, -1, +1, +2, +2, -2, -2};
int dy[]= {-2, -2, +2, +2, -1, +1, +1, -1};
 
int n, m, total, cnt[12][12], temp[12][12], dis[12][12];
 
char grid[12][12];
 
int flag;
 
bool valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
void update();
 
void knight_distance(int st, int en, int val)
{
    memset(temp, -1, sizeof(temp));
 
    queue<pair<int, int> > q;
 
    temp[st][en] = 0;
 
    q.push(make_pair(st, en));
 
    while(!q.empty())
    {
        pair<int, int> top = q.front();
 
        q.pop();
 
        for(int i=0; i<8; i++)
        {
            int x = top.first + dx[i];
            int y = top.second + dy[i];
 
            if(valid(x, y))
            {
                if(temp[x][y] == -1)
                {
                    temp[x][y] = 1 + temp[top.first][top.second];
                    q.push(make_pair(x, y));
                }
            }
        }
    }
 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(temp[i][j]!=-1)
            {
                int jump = (temp[i][j]+val-1)/val;
                temp[i][j] = jump;
            }
        }
    }
 
    update();
 
}
 
void update()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(temp[i][j]!=-1)
            {
                cnt[i][j]++;
                dis[i][j] += temp[i][j];
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
 
 
        total = 0;
        flag = INT_MAX;
        memset(cnt, 0, sizeof(cnt));
        memset(dis, 0, sizeof(dis));
 
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(grid[i][j]!='.')
                {
                    total++;
                    knight_distance(i, j, grid[i][j]-'0');
                }
            }
        }
 
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(cnt[i][j]==total)
                {
                    flag = min(flag, dis[i][j]);
                }
            }
 
        }
 
        printf("Case %d: ", ++cs);
 
        if(flag==INT_MAX) puts("-1");
 
        else printf("%d\n", flag);
 
 
    }
 
    return 0;
 
}
 