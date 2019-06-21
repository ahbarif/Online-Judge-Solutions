#include<bits/stdc++.h>
using namespace std;
int row, col;
int dx[]={+1, -1, 0, 0};
int dy[]={0, 0, +1, -1};

struct node{
    int x, y;
    node(int _x, int _y)
    {
        x=_x; y=_y;
    }
};

bool vis[1005][1005];
int dis[1005][1005];

void bfs(node src, node dst)
{
        memset(dis, 0, sizeof dis);
        queue<node> q;
        q.push(src);
        vis[src.x][src.y] =1;
        dis[src.x][src.y] =0;

        while(!q.empty())
        {
                node top=q.front();
                q.pop();
                if(dst.x==top.x && dst.y==top.y)
                {
                    cout<<dis[top.x][top.y]<<endl;
                    return;
                }

                for(int i=0; i<4; i++)
                {

                    int tx = top.x + dx[i];
                    int ty = top.y + dy[i];

                    if(tx >=0 && tx<row && ty>=0 && ty<col && vis[tx][ty]==0)
                    {
                        vis[tx][ty]=1;
                        dis[tx][ty]=dis[top.x][top.y]+1;
                        q.push(node(tx, ty));
                    }

                }
        }

}

int main()
{

        int i, n, q, x, y, a, b, c;

        while(cin>>row>>col)
        {

            memset(vis, 0, sizeof vis);

             if(!row && !col)   break;
                scanf("%d", &n);

                while(n--)
                {
                    scanf("%d %d", &c, &q);
                    while(q--)
                    {
                        scanf("%d", &x);
                        vis[c][x]=1;
                    }

                }

                scanf("%d %d", &a, &b);
                scanf("%d %d", &x, &y);

                bfs(node(a,b), node(x, y));
        }



        return 0;
}
