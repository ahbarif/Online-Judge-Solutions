#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool compare(pii a, pii b){
     if(a.first==b.first){
         return a.second>b.second;
    }
    return a.first<b.first;
}

int div(int x){
    int s=0;
    for(int i=1; i<=x; i++){
        if(x%i==0)  s++;
    }
    return s;
}

int main(){

    int i, x, n=0;
    vector<pii> a;

    for(i=1; i<1001; i++){
        x=div(i);
        a.push_back(pii(x, i));
    }

    sort(a.begin(), a.end(), compare);

    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &x);
        printf("Case %d: %d\n", ++n, a[x-1].second);
    }
   return 0;
}
