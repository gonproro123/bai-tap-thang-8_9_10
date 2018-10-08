#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, res, a[N], F[N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        F[i] = a[i];
    }
}

void Solve()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                F[i] = max(F[i], F[j] + a[i]);
        }
    }

    for (int i = 1; i <= n; i++)
        res = max(res, F[i]);
    cout << res << '\n';
}

int main()
{
    freopen("MAXIS.INP", "r", stdin);
    freopen("MAXIS.OUT", "w", stdout);
    Input();
    Solve();
    return 0;
}
