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
		int x,n;
		char d,l;
		cin >> n >> x;
		cin >> d >> l;
		map<char, char> m;
		m['H'] = 'E';
		m['E'] = 'H';
		if (d=='L' and x%2==0)
			cout << x << " " << m[l] << "\n";
		else if (d=='L' and x%2==1)
			cout << x << " " << l << "\n";
		else if (d=='R' and x%2==0 and n%2==0)
			cout << n-x+1 << " " << l << "\n";
		else if (d=='R' and x%2==0 and n%2==1)
			cout << n-x+1 << " " << m[l] << "\n";
		else if (d=='R' and x%2==1 and n%2==0)
			cout << n-x+1 << " " << m[l] << "\n";
		else if (d=='R' and x%2==1 and n%2==1)
			cout << n-x+1 << " " << l << "\n";
	}
	return 0;
}