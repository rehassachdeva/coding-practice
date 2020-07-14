// egg drop puzzle
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

#define N 105

int dp[N][N];

int eggDrop(int n, int k)
{
	// DBG(n,k);
	if (k<=1 or n==1)
		return k;
	
	if (dp[n][k]!=-1)
		return dp[n][k];
	
	int mn=INT_MAX,tmp;

	for (int i = 1; i <= k; ++i)
	{
		tmp = 1+max(eggDrop(n-1,i-1), eggDrop(n,k-i));
		mn = min(mn,tmp);
	}

	// DBG(mn);

	return dp[n][k] = mn;
}

int main()
{
	TC()
	{
		memset(dp,-1,sizeof(dp));
		int n,l;
		cin >> n >> l;
		cout << eggDrop(n,l) << "\n";
	}
	return 0;
}