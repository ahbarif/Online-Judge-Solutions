#include<bits/stdc++.h>
using namespace std;

struct node{
    int x, y;
};

inline bool cmp(node a, node b)    { return (a.x==b.x && a.y==b.y);}

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cell[25][25], d[25][25],vis[25][25];

inline int bfs(node source, node to)
{
        memset(vis,0,sizeof vis);
        memset(d, 0, sizeof d);

        vis[source.x][source.y]=1;

        queue<node> q;
        q.push(source);

        while(!q.empty())
        {
            node top=q.front(); q.pop();
            if(cmp(top, to))   return d[top.x][top.y];

            for(int k=0;k<4;k++)
            {
                int tx=top.x+fx[k];
                int ty=top.y+fy[k];
                if(cell[tx][ty]!=-1 && vis[tx][ty]==0)
                {
                    vis[tx][ty]=1;
                    d[tx][ty]=d[top.x][top.y]+1;
                    node p;
                    p.x=tx; p.y=ty;
                    q.push(p);
                }
            }
        }
}

int main()
{

        int row, col, i, j, ans, test, caseno=0;
        node d[5];
        char s[25];

        scanf("%d", &test);

        while(test--)
        {
                memset(cell, 0, sizeof cell);
                scanf("%d %d", &row, &col);
                ans=-1;

                for(i=0; i<row; i++)
                {
                    scanf("%s", s);
                    for(j=0; j<col; j++)
                    {
                        if(s[j]=='#' || s[j]=='m')   cell[i][j]=-1;
                        if(s[j]=='c')   d[1].x=i, d[1].y=j;
                        if(s[j]=='a')   d[2].x=i, d[2].y=j;
                        if(s[j]=='b')   d[3].x=i, d[3].y=j;
                        if(s[j]=='h')   d[4].x=i, d[4].y=j;
                    }
                }

               for(i=1; i<4; i++)
               {
                   int k=bfs(d[i], d[4]);
                   ans=max(ans, k);
               }

               printf("Case %d: %d\n", ++caseno, ans);
        }

    return 0;

}
