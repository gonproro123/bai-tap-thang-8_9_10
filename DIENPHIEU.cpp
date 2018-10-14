#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int n, q, a[N], tree[4 * N];

void Input()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}

void Build(int k, int l, int r)
{
	if (l == r)
	{
		tree[k] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	Build(k * 2, l, mid);
	Build(k * 2 + 1, mid + 1, r);

	tree[k] = max(tree[k * 2], tree[k * 2 + 1]);
}

int Get(int k, int l, int r, int L, int R)
{
	if (l > R || r < L)
		return -1e8;

	if (L <= l && r <= R)
		return tree[k];

	int mid = (l + r) / 2;
	return max(Get(k * 2, l, mid, L, R), Get(k * 2 + 1, mid + 1, r, L, R));
}

int main()
{
	freopen("DIENPHIEU.INP", "r", stdin);
	freopen("DIENPHIEU.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	Input();
	Build(1, 1, n);
	while (q--)
	{
		int u, v; cin >> u >> v;
		cout << Get(1, 1, n, u , v) << '\n';
	}

	return 0;
}