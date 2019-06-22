#include<bits/stdc++.h>
using namespace std;

int a[100015], n;
char str[100015];

bool all(){

    for(int i = 0; i<n; i++){
        if(a[i]!=9) return false;
    }
    return true;
}
void solve(int cs){
    printf("Case %d: ", cs);

    if(all()){
        printf("1");
        for(int i = 1; i<n; i++) printf("0");
        printf("1");
        cout<<endl;
        return;
    }

    int mid = n/2;
    int i = mid-1;
    int j = (n%2?mid+1:mid);
    while(i>=0 && a[i]==a[j]){
        i--;
        j++;
    }

    bool flag = false;

    if(i<0 || a[i]<a[j]) flag = true;

    while (i >= 0) a[j++] = a[i--];


    if(flag){

        int carry = 1;
        i = mid-1;

        if(n%2){
            a[mid] += carry;
            carry = a[mid]/10;
            a[mid] %= 10;
            j = mid+1;
        }
        else j = mid;

        while(i>=0){
            a[i] += carry;
            carry = a[i]/10;
            a[i]%=10;
            a[j++] = a[i--];
        }

    }

        for(int i = 0; i<n; i++) printf("%d", a[i]);
        cout<<endl;




}
int main() {


    int test, cs = 0;

    cin>>test;

    while(test--){
        memset(a, 0, sizeof(a));
        scanf("%s", str);
        n = strlen(str);
        for(int i = 0; str[i]; i++) a[i] = str[i]-'0';
        solve(++cs);
    }


    return 0;
}



