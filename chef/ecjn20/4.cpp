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

int getScore(char p, char q, char r)
{
	int s = 0;
	if (p == 'R')
	{
		s += (q == 'S') + (r == 'S');
		s -= (q == 'P') + (r == 'P');
	}
	else if (p == 'S')
	{
		s += (q == 'P') + (r == 'P');
		s -= (q == 'R') + (r == 'R');
	}
	else if (p == 'P')
	{
		s += (q == 'R') + (r == 'R');
		s -= (q == 'S') + (r == 'S');
	}
	return s;
}

int main()
{
	TC()
	{
		int n, p[3];
		cin >> n;
		char a, b, c;
		p[0] = p[1] = p[2] = 0;
		for(int i=0; i<n; i++)
		{
			cin >> a >> b >> c;
			p[0] += getScore(a, b, c);
			p[1] += getScore(b, a, c);
			p[2] += getScore(c, b, a);
		}
		cout << p[0] << " " << p[1] << " " << p[2] << endl;
	}
	return 0;
}