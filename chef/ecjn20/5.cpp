#include <bits/stdc++.h>
using namespace std;

#define DBG(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

#define COUT(...) __g(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __g(const char* name, Arg1&& arg1) {
  cout << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __g(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cout << arg1 << " ";__g(comma+1, args...);
}

#define TC()  int tc; cin >> tc; for(int tc_ctr=1; tc_ctr<=tc; tc_ctr++)

#define N 10001

int path(vector<int> adj[], int s, int d)
{
	if (s == d)
		return 0;

	bool vis[N];
	memset(vis, false, sizeof(vis));

	queue<pair<int, int> > q;
	q.push({s, 0});
	vis[s] = true;

	// bfs
	while(!q.empty())
	{
		auto f = q.front();

		q.pop();

		if (f.first == d)
			return f.second;

		for (auto v : adj[f.first])
		{
			if (!vis[v])
			{
				vis[v] = true;
				q.push({v, f.second+1});
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> adj[N];
	unordered_map<int, bool> tr;

	TC()
	{
		int n, m, x, e, u, v;
		tr.clear();

		for(int i=0; i<N; i++)
		{
			adj[i].clear();
		}

		cin >> n >> m;
		for (int i=0; i<m; i++)
		{
			cin >> x;
			tr[x] = true;
		}

		// construct graph
		cin >> e;
		for (int i=0; i<e; i++)
		{
			cin >> u >> v;
			if (tr[u] and tr[v])
			{
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		int a, b;
		cin >> a >> b;
		int ans = path(adj, a, b);
		cout << ans << endl;
	}
	return 0;
}
