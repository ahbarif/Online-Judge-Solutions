#include<bits/stdc++.h>
using namespace std;

double H[5005];

void preCal(){

    double res = 0;

    for(int i = 1; i<=5000; i++){
        double tmp = (1.0/i);
        res += tmp;
        H[i] = res;
    }
}

void solve(int cs){

    cout<<fixed<<setprecision(10);

    int n, x, k;

    int nSum = 0, nAvg, nCnt = 0, sSum = 0, sAvg, sCnt = 0;

    scanf("%d", &n);

    for(int i = 0; i<n; i++){
        scanf("%d %d", &k, &x);

        if(x==1){
            sSum += k;
            sCnt++;
        }
        else {
            nSum += k;
            sCnt++;
        }
    }

    cout<<"Case "<<cs<<": "<<sSum+nSum*H[n]<<endl;




}

int main()
{


    preCal();

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){

        solve(++cs);

    }

    return 0;


}

