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
		string a, b;
		cin >> a >> b;
		map<char, bool> m;
		for(int i=0; i<b.size(); i++)
		{
			m[b[i]] = true;
		}
		for (int i=0; i<a.size(); i++)
		{
			if(!m[a[i]])
				cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}