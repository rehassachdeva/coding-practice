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
	
	int n;
	cin >> n;

	long long int ans=0;
	int mat;

	for(int i=0; i<n; i++)
	{
		long long int tmp=0;
		for(int j=0; j<n; j++)
		{
			cin >> mat;
			if (i != j)
			{
				tmp |= mat;
			}
		}
		ans += tmp;
	}

	cout << ans << "\n";
	return 0;
}