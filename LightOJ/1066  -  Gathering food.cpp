#include<bits/stdc++.h>
using namespace std;
int dx[]={+1, -1, 0, 0};
int dy[]={0, 0, +1, -1};

struct node{

    int x, y;
    char val;

    node(){}
    node(int _x, int _y, char _val)
    {
        x=_x; y=_y; val=_val;
    }

};

bool cmp(node a, node b)    { return a.val<b.val; }

char grid[20][20];
int row, vis[20][20], dis[20][20];
node v[100];


void BFS(node src, node dst)
{
        int i, j, tx, ty;

        memset(vis, -1, sizeof vis);
        memset(dis, -1, sizeof dis);

        for(i=0; i<row; i++)
        {
            for(j=0; j<row; j++)
            {
                if(grid[i][j]=='#')             vis[i][j]=-1;
                else if(grid[i][j]=='.')        vis[i][j]= 0;
                else if(grid[i][j]==dst.val)    vis[i][j]= 0;
            }
        }

        queue<node> q;

        q.push(src);
        vis[src.x][src.y]=1;
        dis[src.x][src.y]=0;

        while(!q.empty())
        {
                node top = q.front();
                q.pop();

                if(top.val==dst.val)  return;

                for(i=0; i<4; i++)
                {
                    tx=top.x+dx[i];
                    ty=top.y+dy[i];

                    if(tx>=0 && tx<row && ty>=0 && ty<row && vis[tx][ty]==0)
                    {
                        vis[tx][ty]=1;
                        dis[tx][ty]=dis[top.x][top.y]+1;
                        q.push(node(tx, ty, grid[i][j]));
                    }
                }
        }

}

int main()
{

        int test, caseno=0;

        scanf("%d", &test);

        while(test--)
        {

                scanf("%d", &row);

                int i, j, p=0, f=1, ans=0;

                for(i=0; i<row; i++){
                    scanf("%s", grid[i]);
                    for(j=0; j<row; j++){
                        if(grid[i][j]>='A' && grid[i][j]<='Z')
                            v[p++]=(node(i, j, grid[i][j]));
                    }
                }

                sort(v, v+p, cmp);

                for(int k=0; k<p-1; k++)
                {

                    node source = node(v[k].x, v[k].y, v[k].val);
                    node destination = node(v[k+1].x, v[k+1].y, v[k+1].val);

                    BFS(source, destination);

                    int tmp = dis[v[k+1].x][v[k+1].y];

                    if(tmp<0)
                    {
                        f=0;
                        break;
                    }
                    else
                    {
                        ans+=tmp;
                        grid[source.x][source.y]='.';
                    }

                }

                printf("Case %d: ", ++caseno);
                if(!f)  puts("Impossible");
                else cout<<ans<<endl;
        }

        return 0;
}
