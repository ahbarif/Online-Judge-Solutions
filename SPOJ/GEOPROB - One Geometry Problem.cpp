#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> a, vector<int> b){

    while(a.size()<b.size()) a.push_back(0);
    while(b.size()<a.size()) b.push_back(0);

    int carry = 0;

    vector<int> ret;

    for(int i = 0; i<a.size(); i++){
        int pr = (a[i] + b[i] + carry)%10;
        ret.push_back(pr);
        carry = (a[i] + b[i] + carry)/10;

  //      cout<<"pr = "<<pr<<endl;
    }
    if(carry) ret.push_back(carry);
    return ret;
}

vector<int> subtract(vector<int> a, vector<int> b){

    while(b.size()<a.size()) b.push_back(0);

    int carry = 0;

    vector<int> ret;

    for(int i = 0; i<a.size(); i++){
        b[i] += carry;
        if(b[i]>a[i]){
            ret.push_back(a[i]+10-b[i]);
            carry = 1;
        }
        else{
            carry = 0;
            ret.push_back(a[i]-b[i]);
        }
    }
    return ret;
}

void print(vector<int> v){
    int flag = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i] != 0){
            flag = 1;
        }
        if(flag) printf("%d", v[i]);
    }
    if(!flag) cout<<0;
    cout<<endl;
    return;
}
int main()
{
    int test;

    cin>>test;

    while(test--){
        string b, c, d;
        cin>>b>>c>>d;

        vector<int> bb, cc, dd, ee;

        for(int i = b.size()-1; i>=0; i--) bb.push_back(b[i]-'0');
        for(int i = c.size()-1; i>=0; i--) cc.push_back(c[i]-'0'), ee.push_back(c[i]-'0');
        for(int i = d.size()-1; i>=0; i--) dd.push_back(d[i]-'0');

     //   cout<<"###"<<endl;

        vector<int> foo = add(cc, ee);



        vector<int> goo = add(bb, dd);
   //     reverse(goo.begin(), goo.end());
     //   print(goo);

        vector<int> ret = subtract(foo, goo);
//
        reverse(ret.begin(), ret.end());
//
        print(ret);
    }
}



