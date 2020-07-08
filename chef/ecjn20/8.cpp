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

#define N 100001

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss > se)
		return 0;
	if (ss == se)
	{
		st[si] = arr[ss];
	}
	else
	{
		int mid = ss + (se - ss)/2;

		// Range sum
		st[si] = constructSTUtil(arr, ss, mid, st, 2*si + 1) +
				constructSTUtil(arr, mid+1, se, st, 2*si + 2);
	}
	return st[si];
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int st_size = 2*(int)pow(2, x) - 1;

	// st_size = 4*N;

	int *st = new int[st_size];

	constructSTUtil(arr, 0, n-1, st, 0);

	return st;
}

void updateValue(int *st, int ss, int se, int si, int i, int diff)
{
	if (ss > i or se < i)
		return;

	st[si] += diff;
	if (ss < se)
	{
		int mid = ss + (se - ss)/2;
		updateValue(st, ss, mid, 2*si + 1, i, diff);
		updateValue(st, mid+1, se, 2*si + 2, i, diff);
	}
}

int querySum(int *st, int ss, int se, int si, int qs, int qe)
{
	if (se < qs or ss > qe)
		return 0;
	if (qs <= ss and qe >= se)
		return st[si];

	int mid = ss + (se - ss)/2;
	return querySum(st, ss, mid, 2*si + 1, qs, qe) +
		querySum(st, mid+1, se, 2*si + 2, qs, qe);
}


int main()
{
	int n,a,b,c;
	int arr[N];
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	int *st = constructST(arr, n);

	int q;
	cin >> q;

	for(int i=0; i<q; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
		{
			arr[i] += c;
			updateValue(st, 0, n-1, 0, b-1, c);
		}
		else if(a == 1)
		{
			int s = querySum(st, 0, n-1, 0, b-1, c-1);
			int ans = (int)ceil(s/(c-b+1.0));
			cout << ans << endl;
		}
	}
	return 0;
}
