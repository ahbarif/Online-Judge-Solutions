#include<bits/stdc++.h>
using namespace std;

vector<int> inc;
int a[20];

int main()
{
    int test;

    cin>>test;

    while(test--){
        int n, res = 0;
        cin>>n;

        inc.clear();
        memset(a, 0, sizeof(a));

        for(int i = 0; i<n; i++){
            int d, l;
            char c;
            cin>>d>>l>>c;
            if(l==1 && c=='c') a[d]++;
            else if(l==0 && c=='i') inc.push_back(d);
        }

        for(int i = 0; i<inc.size(); i++){
            for(int j = inc[i]+1; j<=10; j++){
                res += a[j];
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
