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

#define TC()  int tc; scanf("%d", &tc); for(int tc_ctr=1; tc_ctr<=tc; tc_ctr++)

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, a, b;

	TC()
	{
		int x=0, y=0;
		scanf("%d", &n);

		for(int i=0; i<4*n-1; i++)
		{
			scanf("%d %d", &a, &b);
			x^=a;
			y^=b;
		}

		printf("%d %d\n", x, y);
	}
	return 0;
}