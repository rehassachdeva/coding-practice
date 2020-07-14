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

int mat[505][505];

int main()
{
	TC()
	{
		memset(mat,0,sizeof(mat));

		int w,c,x,y;
		cin >> w >> c;
		for (int i = 0; i < c; ++i)
		{
			cin >> x >> y;
			mat[x][y]=1;
		}
		map<pair<int, int>, int> m;

		int ans=0;
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (mat[i][j])
				{
					for (int k = j+1; k < w; ++k)
					{
						if (mat[i][k])
						{
							// DBG(i,j,k);
							ans += m[{j,k}];
							m[{j,k}]++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}