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

#define N 10005

int n, m, a;
int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};

const long long int MOD = 1e9+7;

// For each element, i have a mask which describes
// what all arrays contain it.
bitset<N> masks[22];

int main()
{
	cin >> n >> m;

	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> a;
			masks[a].set(i);
		}
	}

	long long int ans = 0;

	// For each subset of prime numbers
	for(int i=1; i<(1<<8); i++)
	{
		// to get length of subset
		int cnt = 0;

		// Find the mask that describes the arrays
		// which each contain that subset, by taking
		// intersections of the masks for each prime
		bitset<N> s;
		s.set();

		for(int j=0; j<8; j++)
		{
			if (i&(1<<j))
			{
				cnt++;
				s &= masks[primes[j]];
			}
		}

		// number of triplets yc3
		long long int y = s.count();

		// since an x length subset is already counted with
		// its (x-1) length subsets twice.. (once with the new
		// element and once without).. so substract it once
		// where x is even.
		if (cnt%2 == 1)
			ans = (ans + (y*(y-1)*(y-2))/6) % MOD;
		else
			ans = (ans - (y*(y-1)*(y-2))/6) % MOD;
	}

	cout << (ans + MOD) % MOD << endl;

	return 0;
}