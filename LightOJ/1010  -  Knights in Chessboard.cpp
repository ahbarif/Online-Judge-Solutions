#include<bits/stdc++.h>
using namespace std;
int main(){

    int test, n, m, ans=0;
    int even, odd, a, b;

    scanf("%d", &test);

    for(int i=1; i<=test; i++){
        ans=0;
        scanf("%d %d", &n, &m);
        even=n/2;   odd=(n+1)/2;
        if(n==1){
            a=m; b=0;
        }
        else if(m==1){
            a=n; b=0;
        }
        else if(n==2){
            if(m%2==1) {
                a=(m+1)/2;
                b=a;
            }
            else{
                if(m%4==0)  a=m/2;
                else a=(m+2)/2;
                b=a;
            }

        }
        else if(m==2){
                swap(n, m);
         if(m%2==1) {
                a=(m+1)/2;
                b=a;
            }
            else{
                if(m%4==0)  a=m/2;
                else a=(m+2)/2;
                b=a;
            }

        }
        else if(m%2==0){
            a=even*(m/2);
            b=odd*(m/2);
        }
        else{
            a=odd*(m+1)/2;
            b=even*(m/2);
        }
        ans=a+b;

        printf("Case %d: %d\n", i, ans);
    }

return 0;
}