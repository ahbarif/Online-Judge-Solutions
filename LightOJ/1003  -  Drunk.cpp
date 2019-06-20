#include<bits/stdc++.h>
using namespace std;

const int sz = 300000;

map<string, int> id;

vector<int> g[sz];

bool white[sz], gray[sz], black[sz];

int flag, cnt, idx;


void init()
{

    for(int i=0; i<sz; i++) g[i].clear();
    id.clear();
    idx = 1;
    flag = 1;

    memset(gray, 0, sizeof gray);
    memset(black, 0, sizeof black);
    memset(white, 0, sizeof white);

}

void dfs(int node)
{
        gray[node] = true;
        white[node] = true;

        for(int i=0; i<g[node].size(); i++)
        {
            int u = g[node][i];

            if(gray[u]==true)   flag = 0;
            if(black[u])    continue;

            if(white[u]==false) dfs(u);
        }

        gray[node] = false;
        black[node] = true;
}


int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
                string a, b;
                init();

                int m;

                scanf("%d", &m);

                while(m--)
                {
                    cin>>a>>b;
                    if(id[a]==0) id[a]=idx++;
                    if(id[b]==0) id[b]=idx++;

                    g[id[a]].push_back(id[b]);
                }


                for(int i=1; i<idx; i++)
                {
                   if(white[i]==false)  dfs(i);
                }

                printf("Case %d: ", ++cs);

                puts(flag?"Yes":"No");
        }

        return 0;
}
