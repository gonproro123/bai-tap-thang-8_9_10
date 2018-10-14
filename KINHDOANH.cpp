#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m, c_size, cnt, d[N];
bool visited[N];
vector<int> adj[N];

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void DFS(int u)
{
	visited[u] = true, c_size++;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!visited[v])
			DFS(v);
	}
}

void Solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			c_size = 0, DFS(i);
			cnt++, d[cnt] = c_size;
		}
	}

	sort(d + 1, d + cnt + 1);
	cout << d[cnt] + d[cnt - 1] << '\n';
}

int main()
{
	freopen("KINHDOANH.INP", "r", stdin);
	freopen("KINHDOANH.OUT", "w", stdout);
	Input();
	Solve();
	return 0;
}