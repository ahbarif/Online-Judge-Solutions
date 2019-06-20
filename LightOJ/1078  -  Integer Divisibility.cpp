# include<bits/stdc++.h>
using namespace std;

int digit_counter(int n, int d){

    int ans=1, i, p=d, x=d;

    if(d%n==0)  return 1;

    while(true){

        x=((x%n) * (10%n))%n;

        p=((p%n)+(x%n))%n;

        if(p%n==0)  return ans+1;

        ans++;
    }

}

int main(){


    int n, d, test, i, x;

    scanf("%d", &test);

    for(i=1; i<=test; i++){

       scanf("%d %d", &n, &d);

       x=digit_counter(n, d);

       printf("Case %d: %d\n", i, x);

    }

    return 0;
}
