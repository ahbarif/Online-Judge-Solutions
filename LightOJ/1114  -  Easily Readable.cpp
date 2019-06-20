#include<bits/stdc++.h>
using namespace std;
 
map<string, int> occ;
 
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int test, cs = 0;
 
    cin>>test;
 
    while(test--)
    {
        int n, m, res;
        string s;
        occ.clear();
 
        cin>>n;
 
        while(n--)
        {
            cin>>s;
            if(s.length()>2)    sort(s.begin()+1, s.end()-1);
            occ[s]++;
        }
 
        cin>>m;
 
        printf("Case %d:\n", ++cs);
        cin.ignore();
 
        while(m--)
        {
            res = 1;
 
            getline(cin, s);
 
         //   cout<<"#-> "<<s<<endl;
 
            stringstream ss(s);
 
            while(ss>>s)
            {
                if(s.length()>2)    sort(s.begin()+1, s.end()-1);
                res = res*occ[s];
                if(res==0)  break;
            }
 
            printf("%d\n", res);
 
          //  cout<<res<<endl;
        }
    }
}
