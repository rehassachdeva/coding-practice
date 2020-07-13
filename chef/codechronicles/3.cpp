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

#define LL long long int

#define mod 1000000007

LL dp[105][605][105];
int arr[105];
int n,s,k;

LL recur(int idx, int sum, int k)
{
	if (k<0)
		return 0;

	if (idx==0)
	{
		if(sum==s)
			return 1;
		else
			return 0;
	}

	if (dp[idx][sum+300][k] != -1)
		return dp[idx][sum+300][k];

	LL t1 = recur(idx - 1, sum + arr[idx-1], k);
	LL t2 = recur(idx - 1, sum, k);
	LL t3 = recur(idx - 1, sum - arr[idx-1], k - 1);

	dp[idx][sum+300][k] = ((t1+t2)%mod + t3)%mod;
	
	return dp[idx][sum+300][k];
}

int main()
{
	TC()
	{
		memset(dp, -1, sizeof(dp));

		int sum=0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		cin >> s >> k;

		if (s>sum)
		{
			cout << 0 << "\n";
			continue;
		}
		k = min(n,k);
		cout << recur(n,0,k) << "\n";
	}
	return 0;
}