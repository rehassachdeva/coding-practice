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

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<int> sum1(1e6+5,0);
vector<int> sum2(1e6+5,0);

int main()
{
	// fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		int minx=1e7, miny=1e7, maxx=0, maxy=0;

		for (int j = 0; j < 3; ++j)
		{
			cin >> x >> y;
			minx = min(minx, x);
			miny = min(miny, y);
			maxx = max(maxx, x);
			maxy = max(maxy, y);
		}

		sum1[minx+1]++;
		sum2[miny+1]++;
		sum1[maxx]--;
		sum2[maxy]--;
	}

	for (int i=1; i<sum1.size(); i++)
		sum1[i] += sum1[i-1];
	for (int i=1; i<sum2.size(); i++)
		sum2[i] += sum2[i-1];

	int q,c;
	char a,b;
	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		cin >> a >> b;
		cin >> c;

		if (a == 'x')
			cout << sum1[c] << "\n";
		else
			cout << sum2[c] << "\n";
	}

	return 0;
}