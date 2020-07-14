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
		string s;
		cin >> s;
		int i=0;
		int c=0;
		int n=s.size();
		while(i<n)
		{
			int j=i+1;
			while(j<n and s[j]==s[i]) j++;
			if(j-i>=2)
				c+=40;
			else
				c+=8;
			i=j;
		}
		// DBG(n*8,c);
		cout << n*8-c << "\n";
	}
	return 0;
}