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

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main()
{
	fastio;

	TC()
	{
		long long int n,i=2;
		cin >> n;
		while(n%i==0) i*=2;
		cout << n/i << "\n";
	}
	return 0;
}