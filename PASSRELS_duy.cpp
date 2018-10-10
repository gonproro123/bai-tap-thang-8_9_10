#include <bits/stdc++.h>

using namespace std;
ifstream fin("PASSRELS.INP");
ofstream fout("PASSRELS.OUT");
const int SIZE= 1E5+5;
int a[SIZE],n;

void Input()
{
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>a[i];
        sort(a+1,a+n+1);
}

void Solve()
{
    int Count=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0)
            continue;
        if(Count>=a[i])
            continue;
        Count++;
        a[i]=0;
    }
    fout<<Count;
}
int main()
{
    Input();
    Solve();
    return 0;
}
