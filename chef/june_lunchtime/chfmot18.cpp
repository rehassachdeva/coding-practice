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
		int n,s,c=0;
		cin >> s >> n;

		if (s == 1)
		{
			c=1;
		}
		else if (n >= s)
		{
			c = 1 + (s%2);
		}
		else
		{
			c = s/n;
			s = s%n;

			if(s%2 and s>1)
				c+=2;
			else if(s>0)
				c+=1;
		}

		cout << c << "\n";
	}
	return 0;
}