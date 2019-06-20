#include<bits/stdc++.h>
using namespace std;

int main()
{

    int test, a, b, i, p, tc;
    vector<int> ans, top;

    scanf("%d", &test);

    for(tc=0; tc<test; tc++){

        scanf("%d %d", &a, &b);
        p=(a-b);
        int root=(sqrt(a-b));
        for(int j=1; j<=root; j++){
            if(p%j==0) {
                if(j>b) ans.push_back(j);
                if(j*j!=p)
                if(p/j>b) top.push_back(p/j);
            }
        }
        printf("Case %d:", tc+1);
        if(ans.size()==0 && top.size()==0)   printf(" impossible\n");
        else
        {
           for(i=0; i<ans.size(); i++)    printf(" %d", ans[i]);
           for(i=top.size()-1; i>=0; i--) printf(" %d", top[i]);
           puts("");
        }

        ans.clear();    top.clear();
    }


    return 0;

}
