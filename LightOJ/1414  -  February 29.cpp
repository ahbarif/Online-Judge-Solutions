#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const double eps=1e-9;

int month_no(string s){

    string p[13]={"0", "January", "February","March","April","May","June","July","August","September","October","November","December"};
    for(int i=1; i<13; i++) {
        if(p[i]==s) return i;
    }
}

bool leap(int x){

    if(x%400==0 || (x%4==0 && x%100!=0))    return 1;
    return 0;
}

int main(){

  string a, b;
  int d1, d2, y1, y2, ans, m1, m2;
  int test, j, p, q;
  cin>>test;
  for(j=1; j<=test; j++){
    ans=0;
    cin>>a;
    scanf("%d, %d", &d1, &y1);
    cin>>b;
    scanf("%d, %d", &d2, &y2);
    m1=month_no(a); m2=month_no(b);

    if(y2-y1<3){
        for(int i=y1; i<=y2; i++){
            if(leap(i)){
                if(m1<3 && (m2>2 || m2==2 && d2==29))   ans=1;
                else ans=0;
            }
        }
    }

    else{

            p=y1+1;
            q=y2-1;

            ans=(q/4 - q/100 + q/400)-(y1/4 - y1/100 + y1/400);

            if(leap(y1)){
                if(m1<=2) ans++;
            }

            if(leap(y2)){
                if(m2>2 || (m2==2 && d2==29))   ans++;
            }
    }
        printf("Case %d: %d\n", j, ans);
 }

    return 0;
}