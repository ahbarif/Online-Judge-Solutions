#include<bits/stdc++.h>
using namespace std;
int main(){

    int t, a, b, x, y;

    while(cin>>t){

        if(t==0)    break;
        else{

            cin>>a>>b;
            for(int i=0; i<t; i++)

            {
                cin>>x>>y;

                if(x==a || y==b)        cout<<"divisa\n";
                else if(x>a && y>b)     cout<<"NE\n";
                else if(x<a && y>b)     cout<<"NO\n";
                else if(x>a && y<b)     cout<<"SE\n";
                else if(x<a && y<b)     cout<<"SO\n";
            }
        }

    }
return 0;
}
