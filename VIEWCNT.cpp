#include <bits/stdc++.h>

using namespace std;
const int SIZE= 1E5 +5 ;
string S;
int R[SIZE];
int L[SIZE];
int n,a[SIZE];

void Input()
{
    cin >> n;
    for(int i=1; i <= n; i++)
        cin >> a[i];
    cin >> S;
}

void Solve()
{
    deque<int> Q;
    Q.clear();
    Q.push_back(1);

    for(int i=2; i<=n; i++)
    {
        L[i]=Q.size();
        while(!Q.empty() )
        {
            if( a[i] > a[Q.back()])
                Q.pop_back();
            else
                break;
        }

        Q.push_back(i);
    }

    Q.clear();
    Q.push_back(n);
    for(int i=n-1; i>=1; i--)
    {
        R[i]=Q.size();
        while(!Q.empty() )
        {
            if( a[i] > a[Q.back()])
                Q.pop_back();
            else
                break;
        }

        Q.push_back(i);
    }
}
void Out()
{
    for(int i=0; i<S.size(); i++)
        if(S[i] == 'L')
            cout << L[i+1] << " ";
        else
            cout << R[i+1] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("VIEWCNT.INP","r",stdin);
      freopen("VIEWCNT.out","w",stdout);
    Input();
    Solve();
    Out();
    return 0;
}
/*
*/
