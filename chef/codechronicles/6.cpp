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
		int n;
		cin >> n;

		long long int sum=0;
		int a;

		int ans=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			sum += a;
			ans = max(ans, (int)ceil((1.0*sum) / (1.0*(i+1))));
		}

		cout << ans << endl;
	}
	return 0;
}