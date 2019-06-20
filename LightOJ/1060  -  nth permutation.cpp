#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll fac[25];
int freq[26];
 
void pre(){
 
    fac[0] = 1;
 
    for(int i = 1; i<=20; i++) fac[i] = i*fac[i-1];
 
}
 
ll getPermutation(){
 
    ll den = 1LL, nom = 1LL;
    int tot = 0;
 
    for(int i = 0; i<26; i++){
        tot += freq[i];
        den *= fac[freq[i]];
    }
    return fac[tot]/den;
 
 
}
 
int main(){
 
    pre();
 
    int test, cs = 0, n;
 
    scanf("%d", &test);
 
    while(test--){
 
        string s;
        memset(freq, 0, sizeof(freq));
 
        cin>>s>>n;
 
        for(int i = 0; i<s.size(); i++) freq[s[i]-'a']++;
 
        ll perm = getPermutation();
 
        if(perm<n) cout<<"Case "<<++cs<<": Impossible"<<endl;
 
        else{
 
            cout<<"Case "<<++cs<<": ";
 
            for(int i = 0; i<s.size(); i++){
                for(int j = 0; j<26; j++){
 
                    if(freq[j]){
 
 
                        freq[j]--;
 
                        if(getPermutation()>=n){
                            putchar('a' + j);
                            break;
                        }
                        else{
                            n -= getPermutation();
                            freq[j]++;
                        }
                    }
                }
            }
 
            cout<<endl;
 
        }
 
 
    }
 
 
}
