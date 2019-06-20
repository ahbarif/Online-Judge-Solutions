# include<bits/stdc++.h>
using namespace std;

int main()
{
       int a[3], b[3], n, test, caseno=0, area, i, z, x;

       scanf("%d", &test);

       while(test--)
       {

                a[0]=a[1]=a[2]=0;

                b[0]=b[1]=b[2]=1000;

                scanf("%d", &n);

                while(n--)
                {
                        for(i=0; i<3; i++)
                        {
                            scanf("%d", &x);
                            a[i]=max(x, a[i]);
                        }

                        for(i=0; i<3; i++)
                        {
                            scanf("%d", &x);
                            b[i]=min(x, b[i]);
                        }

                }

                if(b[0]>a[0] && b[1]>a[1] && b[2]>a[2])
                {
                    area=(b[0]-a[0])*(b[1]-a[1])*(b[2]-a[2]);
                }
                else area=0;

                printf("Case %d: %d\n", ++caseno, area);

       }

   return 0;
}
