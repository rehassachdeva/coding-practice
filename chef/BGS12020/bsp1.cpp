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

#define N 1000005

vector<bool> isprime(N, true);
vector<long long int> sum(N, 0);

void primeSieve()
{
	for(int i=2; i*i < N; i++)
	{
		if (isprime[i])
		{
			for(int j=i*i; j<N; j+=i)
			{
				isprime[j] = false;
			}
		}
	}
}

void cumSum()
{
	for(int i=2; i<isprime.size(); i++)
	{
		sum[i] = sum[i-1];
		sum[i] += (isprime[i]) ? i : 0;
	}
}

int main()
{
	primeSieve();
	cumSum();

	TC()
	{
		int n;
		cin >> n;
		cout << sum[n] << endl;
	}

	return 0;
}