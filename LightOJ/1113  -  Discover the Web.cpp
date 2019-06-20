#include<bits/stdc++.h>
using namespace std;

int main()
{

       int test, i=1, caseno=0;
       
       string command, url, cur;
       
       vector<string> fforward, backward;

       scanf("%d", &test);

       while(test--)
       {
            printf("Case %d:\n", ++caseno);

            fforward.clear();

            backward.clear();

            cur="http://www.lightoj.com/";

            while(true)
            {
                cin>>command;
                if(command=="QUIT") break;

                if(command=="BACK")
                {
                    if(backward.size()==0)  puts("Ignored");
                    else
                    {
                        fforward.push_back(cur);
                        cur=backward.back();
                        backward.pop_back();
                        cout<<cur<<endl;
                    }
                }

                else if(command=="FORWARD")
                {
                    if(fforward.size()==0)  puts("Ignored");
                    else
                    {
                        backward.push_back(cur);
                        cur=fforward.back();
                        fforward.pop_back();
                        cout<<cur<<endl;

                    }
                }

                else
                {
                    cin>>url;
                    fforward.clear();
                    backward.push_back(cur);
                    cur=url;
                    cout<<cur<<endl;
                }

            }

       }

    return 0;
}