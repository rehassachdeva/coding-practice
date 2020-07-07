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

#define N 1005

vector<int> arr(N);
int n, k, dp[N][N];

int main()
{
	memset(dp, 0, sizeof(dp));

	cin >> n >> k;

	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}

	int ans = 0;

	for (int steps=1; steps<=k; steps++)
	{
		for(int i=1; i<=n; i++)
		{
			if (i == 1)
				dp[i][steps] = max(0, arr[0]);

			int t1 = dp[i-1][steps-1] + arr[i];

			int t2 = 0;

			if (i >= 2)
				t2 = dp[i-2][steps-1] + arr[i];

			dp[i][steps] = max(0, max(t1, t2));

			ans = max(ans, dp[i][steps]);

			// DBG(steps, i, dp[i][steps]);

		}
	}

	cout << ans << endl;

	return 0;
}