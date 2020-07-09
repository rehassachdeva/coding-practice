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

bool cmp(const pair<LL, int> &a, const pair<LL, int> &b)
{
	if (a.first > b.first)
		return true;
	else if (a.first == b.first)
		return (a.second < b.second);
	else
		return false;
}

int main()
{
	TC()
	{
		int n, k, a;
		cin >> n >> k;

		vector<LL> tmp(32, 0);;

		for (int i=0; i<n; i++)
		{
			cin >> a;
			int t=a, b=0;

			while(t)
			{
				if (t&1)
					tmp[b] += (1<<b);
				b++;
				t>>=1;
			}
		}

		vector<pair<LL, int> > ans;

		for (int i=0; i<tmp.size(); i++)
		{
			ans.push_back({tmp[i], i});
		}

		sort(ans.begin(), ans.end(), cmp);

		int ret=0;

		for (int i=0; i<k; i++)
		{
			ret += 1<<(ans[i].second);
		}

		cout << ret << "\n";
	}
	return 0;
}