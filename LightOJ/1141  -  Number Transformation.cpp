#include<bits/stdc++.h>
using namespace std;

int vis[1007], dis[1007], pr[200], p;

bool isprime(int x){
    if(x%2==0 && x!=2)  return 0;
    for(int i=3; i*i<=x; i+=2)
        if(x%i==0)  return 0;
    return 1;
}

void bfs(int source, int to)
{
        memset(vis, 0, sizeof vis);
        memset(dis, 1, sizeof dis);
        queue<int> q;
        q.push(source);
        dis[source]=0;
        int cur, i;
        while(!q.empty())
        {
                cur=q.front();
                q.pop();
                vis[cur]=1;

                if(cur==to){
                    printf("%d\n", dis[cur]);
                    return;
                }

                if(cur<to)
                {
                    for(i=0; pr[i]<cur; i++)
                    {
                        if(cur%pr[i]==0 && cur+pr[i]<=to && vis[cur+pr[i]]==0)
                        {
                            q.push(cur+pr[i]);
                            dis[cur+pr[i]]=min(dis[cur]+1, dis[cur+pr[i]]);
                        }
                    }
                }
        }

    puts("-1");
}

int main() {

    for(int i=2; i<=1007; i++)
        if(isprime(i))
            pr[p++]=i;


        int x, y, test, i;

        scanf("%d", &test);

        for(i=1; i<=test; i++)
        {
            scanf("%d %d", &x, &y);
            printf("Case %d: ", i);
            bfs(x, y);
        }

  return 0;
}
