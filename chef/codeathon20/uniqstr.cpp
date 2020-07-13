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

const int mod = 1e9+7;

unordered_map<int, long long int> m;

long long int calc(int n)
{
	if (n<=1)
		return 0;
	if (n<4)
		return n;
	if (m.find(n) == m.end())
		m[n] = (calc(n-1) + calc(n-2)) % mod;
	return m[n];
}
int main()
{
	string s;
	cin >> s;

	long long int ans=1;
	int n=s.size();
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == 'c' or s[i] =='k')
		{
			cout << 0 << "\n";
			return 0;
		}
		if (s[i] == 'f' or s[i] == 'g')
		{
			int j=i+1;
			while(j<n and s[j]==s[i])
				j++;
			if(j-i>1)
				ans = (ans*calc(j-i)) % mod;
			i=j-1;
		}
	}
	cout << ans << "\n";
	return 0;
}