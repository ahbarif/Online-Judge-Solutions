#include <bits/stdc++.h>
using namespace std;

double nc2(int n){

    double x = n*1.0;
    return (x*(x-1))/2.0;
}

double f(int tiger, int deer){


    double res = 0.0; 
    int tot = tiger+deer+1;
    
    if(tiger == 0) return 1.0;
    // case 1: tiger, me


    // case 2: tiger tiger

   
    double p2 = (tiger*(tiger-1))/(tot*(tot-1.0)) * f(tiger-2, deer);
    res += p2;

    double p = 0;
    // case 3: tiger deer

    if(tiger>0 && deer>0){
           double p3 = (tiger*deer)/(tot*(tot-1.0)) * f(tiger, deer-1);
           res += p3;
    }

    if(deer>1){
        p = (deer*(deer-1))/(tot*(tot-1.0));
    }
 

    return res/(1-p);


    
}

double dp[1005];
bool vis[1005];

double foo(int tiger){

    if(tiger == 0) return 1.0;
    else if(tiger%2) return 0.0;

    if(vis[tiger]) return dp[tiger];
    vis[tiger] = true;
    return dp[tiger] = nc2(tiger)/nc2(tiger+1) * foo(tiger-2);
}


int main()
{
 
     //   freopen("in.txt", "r", stdin);

        cout<<fixed<<setprecision(10);
         
        memset(vis, 0, sizeof(vis));

        int test, cs = 0;

        cin>>test;

        while(test--){

            int t, d;

            cin>>t>>d;

            cout<<"Case "<<++cs<<": "<<foo(t)<<endl;
        }

    return 0;
}

