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

int a,b;

int cnt(int n)
{
	int ans=0;
	if (n >= a) ans += 1 + (n-a)/(a+b);
	if (n >= a+b) ans += 1 + (n-a-b)/(a+b);
	return ans;
}

int main()
{
	TC()
	{
		int l,r;
		cin >> a >> b >> l >> r;

		cout << cnt(r)-cnt(l-1) << endl;
	}
	return 0;
}
