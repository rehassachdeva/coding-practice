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

int main()
{
	TC()
	{
		int n,x;
		cin >> n >> x;

		vector< pair<int, int> > adj[n+1];
		vector<int> a(n+1,0),c(n+1,0);

		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> c[i];
		}
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] != i)
			{
				adj[i].push_back({a[i], c[i]});
			}
			if (i < n)
			{
				adj[i].push_back({i+1, x});
				adj[i+1].push_back({i, x});
			}
		}

		vector<long long int> d(n+1,1e18);

		d[1]=0;
		priority_queue< pair<int, int> > pq;
		pq.push({0,1});

		while (!pq.empty())
		{
			auto cur = pq.top();
			pq.pop();
			for (auto n : adj[cur.second])
			{
				if (d[n.first] > d[cur.second] + n.second)
				{
					d[n.first] = d[cur.second] + n.second;
					pq.push({-d[n.first], n.first});
				}
			}
		}
		cout << d[n] << "\n";

	}
	return 0;
}