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
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	TC()
	{
		int n,k;
		cin >> n >> k;

		vector<int> a(n+5, 0);
		vector<int> dp(n+5, 1e9);
		deque<int> odds, evens;

		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}

		for (int i = 1; i <= k; ++i)
		{
			dp[i] = 1;
			if (a[i]%2)
				odds.push_back(i);
			else
				evens.push_back(i);			
		}

		for (int i = k+1; i <= n; ++i)
		{
			if (a[i]%2)
			{
				for (auto x : odds)
					dp[i] = min(dp[i], dp[x]+1);
				odds.push_back(i);
			}
			else
			{
				for (auto x : evens)
					dp[i] = min(dp[i], dp[x]+1);				
				evens.push_back(i);
			}

			if (a[i-k]%2)
				odds.pop_front();
			else
				evens.pop_front();
		}

		int ans = 1e9;
		for (int i = n-k+1; i <= n; ++i)
		{
			ans = min(ans, dp[i]);
		}

		if (ans == 1e9)
			cout << "-1\n";
		else
			cout << ans+1 << "\n";
	}

	return 0;
}