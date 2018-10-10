#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, res = 1e8, a[N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
}

void Solve()
{
    for (int i = n + 1; i >= 1; i--)
        res = min(res, a[i - 1] + n - i + 1);
    cout << res << '\n';
}

int main()
{
    freopen("PASSRELS.INP", "r", stdin);
    freopen("PASSRELS.OUT", "w", stdout);
    Input();
    Solve();
    return 0;
}
