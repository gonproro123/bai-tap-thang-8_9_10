#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], discover_time, from[N], to[N], From[N], To[N], d[N], tree[4 * N];
vector<int> adj[N];
bool visited[N];

void Input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS(int u)
{
    visited[u] = true;

    discover_time++, from[u] = discover_time;
    d[discover_time] = u;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
            DFS(v);
    }

    to[u] = discover_time;
}

void Build(int k, int l, int r)
{
    if (l == r)
    {
        tree[k] = a[d[l]];
        return;
    }

    int mid = (l + r) / 2;
    Build(k * 2, l, mid);
    Build(k * 2 + 1, mid + 1, r);

    tree[k] = tree[k * 2] + tree[k * 2 + 1];
}

void Update(int k, int l, int r, int idx, int val)
{
    if (l > idx || r < idx)
        return;

    if (l == r)
    {
        tree[k] = val;
        return;
    }

    int mid = (l + r) / 2;
    Update(k * 2, l, mid, idx, val);
    Update(k * 2 + 1, mid + 1, r, idx, val);

    tree[k] = tree[k * 2] + tree[k * 2 + 1];
}

long long Get(int k, int l, int r, int L, int R)
{
    if (l > R || r < L)
        return 0;

    if (L <= l && r <= R)
        return tree[k];

    int mid = (l + r) / 2;
    return (Get(k * 2, l, mid, L, R) + Get(k * 2 + 1, mid + 1, r, L, R));
}

int main()
{
    freopen("SCOMP.INP", "r", stdin);
    freopen("SCOMP.OUT", "w", stdout);
    Input();
    DFS(1);
    Build(1, 1, n);
    while (m--)
    {
        char type; scanf(" %c", &type);
        if (type == 'U')
        {
            int u, x; scanf("%d%d", &u, &x);
            Update(1, 1, n, from[u], x);
        }

        else
        {
            int u; scanf("%u", &u);
            cout << Get(1, 1, n, from[u], to[u]) << '\n';
        }
    }
    return 0;
}