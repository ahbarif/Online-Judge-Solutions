#include<bits/stdc++.h>
using namespace std;
 
char grid[30][30];
 
void traverse(int x, int y)
{
    while(1)
    {
        if(grid[x-1][y]=='.')
        {
            grid[x-1][y]='@';
            traverse(x-1, y);
        }
        else   break;
    }
     while(1)
     {
        if(grid[x+1][y]=='.')
        {
            grid[x+1][y]='@';
            traverse(x+1, y);
        }
        else   break;
     }
     while(1)
     {
        if(grid[x][y+1]=='.')
        {
            grid[x][y+1]='@';
            traverse(x, y+1);
        }
        else   break;
     }
     while(1)
     {
        if(grid[x][y-1]=='.')
        {
            grid[x][y-1]='@';
            traverse(x, y-1);
        }
        else   break;
     }
 
}
int main(){
 
        int n, i, c, j, test, tc=0, ans, r, x, y;
 
        string s;
 
        cin>>test;
 
        while(test--)
        {
                ans=0;
                for(i=0; i<=22; i++)
                {
                    for(j=0; j<=22; j++) grid[i][j]='#';
                }
 
                cin>>c>>r;
 
                for(i=1; i<=r; i++){
                    cin>>s;
                    for(j=1; j<=c; j++) grid[i][j]=s[j-1];
                }
 
                for(i=0; i<=r; i++)
                {
                    for(j=0; j<=c; j++)
                    {
                        if(grid[i][j]=='@')
                        {
                            x=i, y=j;
                            break;
                        }
                    }
                }
                traverse(x, y);
                for(i=1; i<=r; i++)
                {
                   for(j=1; j<=c; j++)
                   {
                       if(grid[i][j]=='@')  ans++;
                   }
                }
 
            cout<<"Case "<<++tc<<": "<<ans<<endl;
        }
 
 
    return 0;
 
}