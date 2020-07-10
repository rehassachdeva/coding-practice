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
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	TC()
	{
		int n;
		string s;
		cin >> n >> s;
		if (n != 1)
		{
			sort(s.begin(), s.end());
			cout << s << "\n";
		}
		else
		{
			int idx=0;
			for(int i=1; i<s.size(); i++)
			{
				if(s[i]<s[idx])
					idx=i;
			}

			vector<string> cands;

			for(int i=0; i<s.size(); i++)
			{
				if (s[i] == s[idx])
				{
					cands.push_back(s.substr(i) + s.substr(0,i));
				}
			}

			cout << (*min_element(cands.begin(), cands.end()));
			cout << "\n";
		}
	}
	return 0;
}