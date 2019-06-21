#include<bits/stdc++.h>
using namespace std;

int indegree[1005], n;

vector<int> g[1005];
vector<int> nodes, gg;
bool flag = 0;

void split(string s)
{
    memset(indegree, 0, sizeof(indegree));
    for(int i = 0; i<1005; i++) g[i].clear();

    string a;
    stringstream ss(s);

    while(ss>>a)
    {
        nodes.push_back(a[0] - 'A');
    }
}

void input(string s)
{
    string a;
    stringstream ss(s);

    while(ss>>a)
    {

        int u = a[0] - 'A';
        int v = a[2] - 'A';
        indegree[v]++;
        g[u].push_back(v);
    }

}

void dfs(vector<int>& res, bool visited[])
{

    for (int i = 0; i < nodes.size(); i++)
    {

        int x = nodes[i];

        if (indegree[x] == 0 && !visited[x])
        {

            for (vector<int>:: iterator it = g[x].begin(); it != g[x].end(); it++)
            {
                indegree[*it]--;
            }

            res.push_back(x);
            visited[x] = true;
            dfs(res, visited);

            visited[x] = false;
            res.pop_back();

            for (vector<int>:: iterator it = g[x].begin(); it != g[x].end(); it++)
            {
                indegree[*it]++;
            }
        }
    }

    if(res.size()==nodes.size())
    {
        flag = 1;
        for (int i = 0; i < res.size(); i++)
        {
            char c = res[i] + 'A';
            printf("%c", c);
            if(i==res.size()-1)   puts("");
            else printf(" ");
        }
    }
}


int main()
{
    int test;

    scanf("%d", &test);

    cin.ignore();
    string s;

    for(int tc = 1; tc<=test; tc++)
    {
        cin.ignore();

        nodes.clear();

        getline(cin, s);
        split(s);

        getline(cin, s);
        input(s);

        bool visited[1005];

        gg.clear();
        memset(visited, 0, sizeof(visited));

        sort(nodes.begin(), nodes.end());

        dfs(gg, visited);

        if(flag==0)
        {
            puts("NO");
        }

        flag = 0;

        if(tc<test) puts("");

    }
}
