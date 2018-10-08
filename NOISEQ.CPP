#include <bits/stdc++.h>
using namespace std;
 
const int SIZE = 1E5+5;
int a[SIZE],n;
int R;
map<int,int> check;
int b[SIZE];
void Input()
{
    cin>>n>>R;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}
void Solve()
{
    int temp=-R;
    for(int i=1;i<=n;i++)
    {
        while(check[a[i]-temp]&&temp<=R)
            temp++;
            if(temp>R)
                break;
        b[i]=a[i]-temp;
        check[a[i]-temp]=1;
    }
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
 
}
int main()
{
    freopen("NOISEQ.INP","r",stdin);
    freopen("NOISEQ.OUT","w",stdout);
    Input();
    Solve();
    return 0;
}
 
