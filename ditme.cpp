#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n, p, q, a[N], T1[N], T2[N];
bool check[N];

void Input()
{
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve(int sum_1, int sum_2, int t1, int t2, int type, int last)
{
    if (type == 1) T1[t1] = last;
    else if (type == 2) T2[t2] = last;

    if (t1 + t2 == n)
    {
        cout << t1 << " ";
        for (int i = 1; i <= t1; i++)
            cout << T1[i] << " ";
        cout << '\n' << t2 << " ";
        for (int i = 1; i <= t2; i++)
            cout << T2[i] << " ";
        cout << '\n';
        exit(0);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i] && sum_1 + a[i] <= p)
        {
            check[i] = true;
            Solve(sum_1 + a[i], sum_2, t1 + 1, t2, 1, i);
            check[i] = false;
        }

        if (!check[i] && sum_2 + a[i] <= q)
        {
            check[i] = true;
            Solve(sum_1, sum_2 + a[i], t1, t2 + 1, 2, i);
            check[i] = false;
        }
    }
}

/*
3 4 3
3 2 2
*/

int main()
{
    //freopen("ORD2CHAT.INP", "r", stdin);
    //freopen("ORD2CHAT.OUT", "w", stdout);
    Input();
    Solve(a[1], 0, 1, 0, 1, 1);
    Solve(0, 0, 0, 0, 0, 0);
    cout << -1 << '\n';
    return 0;
}
