#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, res, a[N], Max[N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        Max[i] = max(Max[i - 1], a[i]);
}

void Solve()
{
    for (int i = n; i >= 1; i--)
    {
        if (Max[i - 1] <= n - i + 1)
        {
            cout << n - i + 1 << '\n';
            return;
        }
    }
}

int main()
{
    freopen("PASSRELS.INP", "r", stdin);
    freopen("PASSRELS.OUT", "w", stdout);
    Input();
    Solve();
    return 0;
}
