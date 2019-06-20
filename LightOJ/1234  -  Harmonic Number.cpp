#include<bits/stdc++.h>
using namespace std;
vector<double> harmony;
int main(){
 
    int N = 100000000+1000, i, j;
    int start, end, n, test, val;
    harmony.push_back(0);
    double k, s = 0;
 
    for (i = 1; i < N; i++){
        k = 1.0 / i;
        s += k;
        if (i%1000 == 0)    harmony.push_back(s);
    }
 
    scanf("%d", &test);
    for (i = 0; i < test; i++){
        scanf("%d", &n);
        
        start=n / 1000;
        s = harmony[start];
 
       end = n % 1000; val = ((start) * 1000)+1;
 
        for (j = 0; j < end; j++){
            k = 1.0 / val;
            s += k;
            val++;
        }
        printf("Case %d: %.10lf\n", i + 1, s);
    }
 
 
 
    return 0;
}