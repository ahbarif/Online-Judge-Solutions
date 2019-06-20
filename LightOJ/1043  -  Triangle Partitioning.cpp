# include<bits/stdc++.h>
using namespace std;
 
double area(double a, double b, double c){
 
    double s=(a+b+c)*0.50;
 
    return sqrt(s*(s-a)*(s-b)*(s-c));
 
}
 
int bisection(double a, double b){
 
    if(abs(b-a)<=0.0000000001)    return 0;
 
    else if(a>b)                return 1;
 
    return 2;
 
}
 
int main(){
 
 
    int n, test, i;
 
    double ab, bc, ac, area_abc, ad, area_ade, rat, r2, ae, de, low, high, mid;
 
    scanf("%d", &test);
 
    for(i=1; i<=test; i++){
 
       scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &rat);
 
       area_abc=area(ab, bc, ac);
 
       low=0.0, high=ab;
 
       while(true){
 
            ad=(high+low)/2.0;
 
            ae=(ad*ac)/ab;
 
            de=(ad*bc)/ab;
 
            area_ade=area(ad, ae, de);
 
            r2=area_ade/(area_abc-area_ade);
 
            n=bisection(r2, rat);
 
            if(n==0)         break;
 
            else if(n==1)    high=ad;
 
            else             low=ad;
 
 
       }
 
        printf("Case %d: %.8lf\n", i, ad);
 
    }
 
    return 0;
}