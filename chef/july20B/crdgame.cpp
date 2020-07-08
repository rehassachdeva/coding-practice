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

#define COUT(...) __g(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __g(const char* name, Arg1&& arg1) {
  cout << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __g(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');cout << arg1 << " ";__g(comma+1, args...);
}

#define TC()  int tc; cin >> tc; for(int tc_ctr=1; tc_ctr<=tc; tc_ctr++)

int getSum(int num)
{
	int ans = 0;
	while(num)
	{
		ans += num%10;
		num /= 10;
	}
	return ans;
}

int main()
{
	TC()
	{
		int n, a, b;
		long long int sa, sb, chef, morty;
		sa = sb = chef = morty = 0;

		cin >> n;

		for(int i=0; i<n; i++)
		{
			cin >> a >> b;
			sa = getSum(a);
			sb = getSum(b);

			if (sa == sb)
			{
				chef++;
				morty++;
			}
			else if (sa > sb)
				chef++;
			else
				morty++;
		}

		if (chef == morty)
		{
			cout << "2 " << chef << endl;
		}
		else if (chef > morty)
		{
			cout << "0 " << chef << endl;
		}
		else
			cout << "1 " << morty << endl;
	}
	return 0;
}