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
	vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

	TC()
	{
		string a;
		cin >> a;
		int ans=0;
		for (auto c : a)
		{
			vector<int> tmp;
			for(auto v : vowels)
			{
				tmp.push_back(abs(v-c));
			}
			sort(tmp.begin(), tmp.end());
			ans += tmp[0];
		}
		cout << ans << "\n";
	}
	return 0;
}