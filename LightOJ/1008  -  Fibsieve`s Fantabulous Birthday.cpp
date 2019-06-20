#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, row, col, test, d1, d2, n1, n2, p, q;

    long double x1, x2;

    cin>>test;

    for(i=1; i<=test; i++){

        cin>>n;

        x1=(1+sqrt(4*n-3))/2.0;
        x2=(1-sqrt(4*n-3))/2.0;

        if(x1==(long long)x1)   row=x1, col=x1;

        else{
            n1=ceil(x1);
            n2=ceil(-x2);

            p=(n1*(n1-1))+1;
            q=(n2*(n2-1))+1;

            d1=p-n;
            d2=n-q;

            if(d1<=d2){
                if(n1%2==0)  {
                    if(n<p) row=n1, col=n1-(p-n);
                    else col=n1, row=n1-(p-n);
                }
                else{
                    if(n<p) col=n1, row=n1-(p-n);
                    else row=n1, col=n1-(p-n);
                }
            }
            else{
                    if(n2%2==1){
                    if(n<p) row=n2, col=n2-(p-n);
                    else col=n2, row=n2-(p-n);
                }
                else{
                    if(n<p) col=n2, row=n2-(p-n);
                    else row=n2, col=n2-(p-n);
                }
            }
        }

    row=abs(row); col=abs(col);

    cout<<"Case "<<i<<": "<<col<<" "<<row<<endl;


}
    return 0;
}