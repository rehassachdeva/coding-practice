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
		int n;
		cin >> n;
		int cnt[3]={0,0,0};
		int a,flg=0;

		for (int i = 0; i < n; ++i)
		{
			cin >> a;

			if (a==10)
			{
				if (cnt[0]>0)
				{
					cnt[0]--;
				}
				else
				{
					flg=1;
				}
			}
			if (a==15)
			{
				if (cnt[1]>0)
				{
					cnt[1]--;
				}
				else if (cnt[0]>1)
				{
					cnt[0]-=2;
				}
				else
				{
					flg=1;
				}
			}

			cnt[a/5-1]++;			
		}

		if (flg==1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}