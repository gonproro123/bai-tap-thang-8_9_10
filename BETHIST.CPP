#include <bits/stdc++.h>

using namespace std;
const int SIZE= 1E4 +5 ;
int a[SIZE],n,res[SIZE];
 int c,d;
void Solve(int i,int point)
{
    if(i>n)
    {
        for(int i=1;i<=n;i++)
            cout<<res[i];
        exit(0);
    }
    if(point -a[i] >=c &&point -a[i]<=d)
    {
        res[i]=0;
        Solve(i+1,point-a[i]);
    }
    if(point +a[i] >=c &&point +a[i]<=d)
    {
        res[i]=1;
        Solve(i+1,point+a[i]);
    }
}
int main()
{
    freopen("BETHIST.INP","r",stdin);
    freopen("BETHIST.OUT","w",stdout);

    cin>>n>>c>>d;
    int Sum=0;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    Solve(1,0);
    cout<<"Impossible";
    return 0;
}
