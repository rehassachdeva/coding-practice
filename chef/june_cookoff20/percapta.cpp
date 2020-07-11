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

#define TC()  int tc; cin >> tc; for(int tc_ctr=1; tc_ctr<=tc; tc_ctr++)

#define N 200005

bool vis[N], maxpr[N];
int a[N],b[N];
vector<int> adj[N];
vector<int> ans,cur;

void dfs(int s)
{
	vis[s] = true;
	cur.push_back(s);

	for (auto nei : adj[s])
	{
		if (!vis[nei] and maxpr[nei])
			dfs(nei);
	}
}

int main()
{
	TC()
	{
		int n,m;
		cin >> n >> m;

		for (int i = 1; i <= n; ++i)
		{
			adj[i].clear();
			vis[i] = maxpr[i] = false;
		}	

		for(int i=1; i<=n; i++)
			cin >> a[i];
		for(int i=1; i<=n; i++)
			cin >> b[i];

		int u,v;
		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}			

		int num=a[1],den=b[1];
		for (int i = 2; i <= n; ++i)
		{
			if (a[i]*den > b[i]*num)
			{
				num=a[i];
				den=b[i];
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			if (a[i]*den == b[i]*num)
				maxpr[i] = true;
		}

		ans.clear();
		cur.clear();
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i] and maxpr[i])
			{
				cur.clear();
				dfs(i);
				if (ans.size() < cur.size())
				{
					ans = cur;
				}
			}
		}

		cout << ans.size() << "\n";
		for (int i=0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}