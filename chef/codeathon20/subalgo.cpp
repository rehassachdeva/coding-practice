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
	int n,a;
	cin >> n >> a;
	string s=to_string(n);
	vector<char> tmp(s.begin(), s.end());

	int i=tmp.size()-1;
	while(a>0 and i>=0)
	{
		if(tmp[i] == '0')
		{
			i--;
			tmp.pop_back();
		}
		else
		{
			tmp[i]--;
		}
		a--;
	}
	if (i<0)
		cout << 0 << "\n";
	else
		cout << string(tmp.begin(), tmp.end()) << "\n";
	return 0;
}