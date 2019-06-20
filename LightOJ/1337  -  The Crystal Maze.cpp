#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
 
int dx[]={+1, -1, 0, 0};
int dy[]={0, 0, +1, -1};
int ans[505][505];
int row, col;
char grid[505][505];
bool vis[505][505];
 
void traverse(PII a)
{
        memset(vis, 0, sizeof vis);
 
        int cur=0, tx, ty, i, j;
 
        queue<PII> q;
        q.push(a);
 
        vis[a.first][a.second]=1;
        if(grid[a.first][a.second]=='C')    cur++;
 
        while(!q.empty())
        {
                PII top = q.front();
                q.pop();
 
                for(i=0; i<4; i++)
                {
                    tx = top.first+dx[i];
                    ty = top.second+dy[i];
 
                    if(tx>=0 && ty>=0 && tx<row && ty<col)
                    {
                        if(grid[tx][ty]!='#' && vis[tx][ty]==0)
                        {
                            vis[tx][ty]=1;
                            q.push(make_pair(tx, ty));
                            if(grid[tx][ty]=='C')   cur++;
                        }
                    }
                }
 
        }
 
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            if(vis[i][j]==1)    ans[i][j]=cur;
 
 
}
 
int main()
{
 
        int T, caseno=1;
 
        scanf("%d", &T);
 
        for(caseno=1; caseno<=T; caseno++)
        {
                memset(ans, -1, sizeof ans);
 
                int query, i, x, y;
 
                scanf("%d %d %d", &row, &col, &query);
 
                for(i=0; i<row; i++)    scanf("%s", grid[i]);
 
                printf("Case %d:\n",caseno);
                while(query--)
                {
                    scanf("%d %d", &x, &y);
 
                    x-=1; y-=1;
 
                    if(ans[x][y]==-1)   traverse(make_pair(x, y));
 
                    printf("%d\n", ans[x][y]);
 
                }
 
        }
 
        return 0;
}