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
		int l,r;
		cin >> l >> r;

		if (l==r)
		{
			if(l==3 or l==9 or l==15 or l==21)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			int ans;
			ans = (r-l)*2;
			if (l<3 and 3<r) ans--;
			if (l<9 and 9<r) ans--;
			if (l<15 and 15<r) ans--;
			if (l<21 and 21<r) ans--;
			cout << ans << endl;
		}
	}
	return 0;
}