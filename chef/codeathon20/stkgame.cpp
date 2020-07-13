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
	int n,cnt=1;
	cin >> n;

	long long int a[n],h[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i] >> h[i];
	}
	for (int i = 1; i < n-1; ++i)
	{
		if (a[i] - h[i] > a[i-1])
		{
			cnt++;
		}
		else if (a[i] + h[i] < a[i+1])
		{
			cnt++;
			a[i] = a[i] + h[i];
		}
	}
	if (n>1) cnt++;
	cout << cnt << "\n";
	return 0;
}