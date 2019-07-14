#include<bits/stdc++.h>
using namespace std;

bool given[105];
int vis[105];
int target[105];
vector<pair<int, int> > adj[105];

bool verdict, flag;
int root;

void true_dfs(int u, bool hobe){
    vis[u] = 1;

   // cout<<u<<" "<<hobe<<endl;

    if(u == root){
        for(auto it:adj[u]){
            int v = it.first;
            int f = it.second;
            true_dfs(v, f);
        }
        return;
    }


    for(auto it:adj[u]){
        int v = it.first;
        int f = it.second;

        if(v == root){
            bool root_hobe;

            if(hobe == true && given[u] == false) flag = false;
            else if(hobe == false && given[u] == true) flag = false;

        }
        else{
            if(vis[v]) continue;

            if(hobe == true){
                true_dfs(v, f);
            }
            else true_dfs(v, !f);
        }

    }
}

void false_dfs(int u, bool hobe){
    vis[u] = 1;


    if(u == root){
        for(auto it:adj[u]){
            int v = it.first;
            int f = it.second;
            false_dfs(v, !f);
        }
        return;
    }


    for(auto it:adj[u]){
        int v = it.first;
        int f = it.second;

        if(v == root){
            bool root_hobe;

            if(hobe == true && given[u] == true) flag = false;
            else if(hobe == false && given[u] == false) flag = false;

        }
        else{
            if(vis[v]) continue;

            if(hobe == true){
                false_dfs(v, f);
            }
            else false_dfs(v, !f);
        }

    }
}

void solve(int n){
    flag = true;

    for(int i = 1; i<=n; i++) adj[i].clear();

    for(int i = 1; i<=n; i++){
        cin>>target[i];
        string s;
        cin>>s;
        if(s == "false") given[i] = false;
        else given[i] = true;

        if(target[i]==i && s == "false") flag = 0;

        if(i != target[i]) adj[i].push_back(make_pair(target[i], given[i]));
    }

    if(!flag){
        cout<<"PARADOX"<<endl;
        return;
    }

    for(int i = 1; i<=n; i++){
        root = i;
        verdict = true;
        memset(vis, 0, sizeof(vis));

        true_dfs(i, 1);

    //    cout<<""<<endl;

        verdict = false;
        memset(vis, 0, sizeof(vis));
        false_dfs(i, 1);

    }

        if(!flag){
            cout<<"PARADOX"<<endl;
            return;
        }
    cout<<"NOT PARADOX"<<endl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    while(cin>>t && t) solve(t);
    return 0;


}
