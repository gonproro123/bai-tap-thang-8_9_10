#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;

int s, k, F[N], res[N];

void get_fibo()
{
    F[0] = -1, F[1] = 1, F[2] = 2;
    for (int i = 3; i <= N - 5; i++)
        F[i] = F[i - 1] + F[i - 2];
}

void Print(int n)
{
    for (int i = 1; i < n; i++)
        cout << res[i] << "+";
    cout << res[n] << '\n';
}

void Solve(int i, int last, int c, int cnt, int sum)
{
    res[cnt] = F[i];
    if (sum > s)
        return;
    if (sum == s)
    {
        Print(cnt);
        return;
    }

    if (F[i] == last && c + 1 <= k)
        Solve(i, last, c + 1, cnt + 1, sum + F[i]);

    for (int t = i + 1; t <= N - 5; t++)
    {
        if (sum + F[t] > s) return;
        Solve(t, F[t], 1, cnt + 1, sum + F[t]);
    }
}

int main()
{
    freopen("FIBRP.INP", "r", stdin);
    freopen("FIBRP.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    get_fibo();
    cin >> s >> k;
    Solve(0, 0, 0, 0, 0);
    return 0;
}
