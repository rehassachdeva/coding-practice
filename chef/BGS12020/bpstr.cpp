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

int main()
{
	int n;
	cin >> n;

	set<string> pile;

	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		pile.insert(s);
	}

	int m;
	cin >> m;
	string b;
	cin >> b;

	int ans = 0;
	for(auto s : pile)
	{
		if (b.find(s) != string::npos)
			ans++;
	}

	cout << ans << endl;

	return 0;
}