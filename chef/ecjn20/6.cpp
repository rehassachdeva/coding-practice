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

#define N 1001

bool path(vector<int> adj[], int s, int d)
{
	if (s == d)
		return true;

	bool vis[N];
	memset(vis, false, sizeof(vis));

	queue<int> q;
	q.push(s);
	vis[s] = true;

	// bfs
	while(!q.empty())
	{
		auto f = q.front();

		q.pop();

		if (f == d)
			return true;

		for (auto v : adj[f])
		{
			if (!vis[v])
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return false;
}

int main()
{
	vector<int> adj[N];
	unordered_map<string, int> m;
	int v;
	TC()
	{
		v = 0;
		m.clear();
		for(int i=0; i<N; i++)
			adj[i].clear();
		
		int n;
		string a, b;
		
		cin >> n >> a >> b;
		
		m[a] = v++;
		m[b] = v++;

		for(int i=0; i<n; i++)
		{
			cin >> a >> b;

			if (m.find(a) == m.end())
			{
				m[a] = v++;
			}
			if (m.find(b) == m.end())
			{
				m[b] = v++;
			}

			adj[m[a]].push_back(m[b]);
			adj[m[b]].push_back(m[a]);
		}

		bool ans = path(adj, 0, 1);

		if (ans)
		{
			cout << "Quarantine\n";
		}
		else
		{
			cout << "Stay Home, Stay Safe\n";
		}
	}
	return 0;
}
