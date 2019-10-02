#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int initial_solve[maxn], penalty[maxn];
vector<int> vec[maxn];

bool solve(){
    for(int i = 0; i<maxn; i++) vec[i].clear();

    int n;

    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        int id, m, x;
        scanf("%d", &id);
        scanf("%d %d", &initial_solve[id], &penalty[id]);
        scanf("%d", &m);
        while(m--){
            scanf("%d", &x);
            vec[id].push_back(x);
        }
    }

    vector<int> ranklist(n);
    for(int i = 0; i<n; i++) scanf("%d", &ranklist[i]);

    int ff = ranklist[0];
    int prevSolve = initial_solve[ff] + vec[ff].size();
    int prevPen = accumulate(vec[ff].begin(), vec[ff].end(), penalty[ff]);

    for(int i = 1; i<ranklist.size(); i++){
        int tm = ranklist[i];
        int solved = initial_solve[tm];
        int curPen = penalty[tm];
        if(solved>prevSolve) return false;
        else if(solved == prevSolve && curPen<prevPen) return false;

        for(auto it:vec[tm]){
            if((solved+1 < prevSolve) || ((solved+1 == prevSolve) && (curPen + it >= prevPen))){
                solved++;
                curPen += it;
            }
            else break;
        }

        prevSolve = solved;
        prevPen = curPen;
    }

    return true;
}

int main(){

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){
        printf("Case %d: ", ++cs);
        printf(solve()?"We respect our judges :)\n":"Say no to rumour >:\n");
//        solve();
    }
    return 0;
}
