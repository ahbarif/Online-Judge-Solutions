#include<bits/stdc++.h>
using namespace std;
int main(){
 	

    int t, i;
    long long int k, n, m;
    cin>>t;
    for(i=1; i<=t; i++){
        cin>>k;
        if(k%2!=0)      cout<<"Case "<<i<<": Impossible"<<endl;

        else if(k==2)   cout<<"Case "<<i<<":1 2"<<endl;

        else {
            m=2;
            n=k/2;
            while(n%2==0){
                n=n/2;
                m*=2;
            }
 
 
            cout<<"Case "<<i<<": "<<n<<" "<<m<<endl;
        }
    }
 
return 0;
}
 