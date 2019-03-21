#include<bits/stdc++.h>
using namespace std;

int a[2005];

int main(){

    int n;

    while(scanf("%d", &n) && n>0){

        for(int i = 0; i<n; i++) scanf("%d", &a[i]);

        sort(a, a+n);

        int ret = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int sum = a[i] + a[j];
                int pos = upper_bound(a, a+n, sum) - a;
                ret += (n - pos);
            }
        }

        cout<<ret<<endl;

    }
    return 0;


}



