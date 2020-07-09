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
		int n, a, mx=INT_MIN;
		cin >> n, a;
		map<int, int> m;
		m.clear();

		for (int i=0; i<n; i++)
		{
			cin >> a;
			m[a]++;
			mx = max(mx, a);
		}

		bool flg = 0;
		for (auto c : m)
		{
			if (c.second > 2)
			{
				cout << "NO\n";
				flg = 1;
				break;
			}
		}
		if (flg)
			continue;

		if (m[mx] > 1)
		{
			cout << "NO\n";
			flg = 1;
			continue;
		}

		cout << "YES\n";
		vector<int> tmp;
		for(auto c : m)
		{
			cout << c.first << " ";
			if (c.second > 1)
				tmp.push_back(c.first);
		}

		sort(tmp.begin(), tmp.end(), greater<int>());

		for (auto c : tmp)
			cout << c << " ";

		cout << "\n";
	}

	return 0;
}