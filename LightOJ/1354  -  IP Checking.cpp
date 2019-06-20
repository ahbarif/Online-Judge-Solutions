#include<bits/stdc++.h>
using namespace std;
int dec(int x){

int s=0, p=0, y;
int a[8];
while(x>0){
    a[p]=x%10;
    y=a[p]*pow(2, p);
    s+=y;
    p++;
    x=x/10;

}
return s;
}
int main(){

    int t, a, b, c, d, p, q, r, s, i;
    cin>>t;
    for(i=1; i<=t; i++){
        scanf("%d.%d.%d.%d\n", &a, &b, &c, &d);
        scanf("%d.%d.%d.%d", &p, &q, &r, &s);
        if(dec(p)==a && dec(q)==b && dec(r)==c && dec(s)==d)    printf("Case %d: Yes\n", i);
        else printf("Case %d: No\n", i);
    }
return 0;

}
