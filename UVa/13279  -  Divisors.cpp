#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000005;

bool mark[maxn];
int prime[maxn], pid;

const int64_t mod = 100000007LL;


int main() {


    prime[pid++] = 2;

    for(int i = 4; i<=maxn-5; i+=2) mark[i] = true;

    for(int i = 3; i<=maxn-5; i+=2){
        if(mark[i]==false){
            prime[pid++] = i;
            for(int j = 2*i; j<maxn; j+=i) mark[j] = true;
        }
    }

    int n;

    while(cin>>n && n){

        long long ret = 1;

        for(int i = 0; i<pid; i++){
            if(prime[i]>n) break;

            int p = prime[i], tp = prime[i], tn = n;

            int64_t t = 0;

            while(tn){

                int64_t a = tn/p;

                t += a*(n%tp+1) + (a)*(a-1)/2*tp;

                tn /= p;

                tp *=p;

            }

            if(t>=mod) t%=mod;

            ret = (ret*(t+1));

            ret %= mod;
        }

        cout<<ret<<endl;
    }

	return 0;
}
