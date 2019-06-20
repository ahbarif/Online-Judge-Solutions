# include<bits/stdc++.h>
using namespace std;

string next_per(string s)
{
        int i, j, n=s.length(), flag=0;

        for(i=n-1; i>0; i--)
        {
            if(s[i]>s[i-1]){
                flag=1;
                i=i-1;
                break;
            }
        }
        if(!flag)   return "0";

        for(j=n-1; j>i; j--)
        {
            if(s[j]>s[i])
            {
                swap(s[i], s[j]);
                break;
            }
        }

        reverse(s.begin()+i+1, s.end());

       return s;

}

int main(){


            int test, caseno=0, i, n, k;

            string s;

            scanf("%d", &test);

            while(test--)
            {
                    scanf("%d %d", &n, &k);

                    s="";

                    for(i=0; i<n; i++)  s=s+(char)(65+i);
                    cout<<"Case "<<++caseno<<":\n";
                    cout<<s<<endl;
                    --k;

                    while(k--)
                    {
                        s=next_per(s);
                        if(s=="0") break;
                        cout<<s<<endl;
                    }

            }
    return 0;
}
