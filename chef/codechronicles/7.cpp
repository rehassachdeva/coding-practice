// segment tree iterative
// bitset array, bitset segment tree
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

#define N 100005
#define M 2005

int n;
int arr[N];

bitset<M> st[4*N];

void constructST(int ss, int se, int si)
{
	if (ss > se)
		return;
	if (ss == se)
	{
		st[si].set(arr[ss]);
		return;
	}
	int mid = ss + (se - ss)/2;
	constructST(ss, mid, 2*si + 1);
	constructST(mid+1, se, 2*si + 2);
	st[si] = st[2*si + 1]^st[2*si + 2];
}

void update(int ss, int se, int si, int i, int v)
{
	if (ss > se)
		return;

	if (ss == se)
	{
		st[si][arr[i]] = v;
		return;
	}
	
	int mid = ss + (se - ss)/2;
	if (i<=mid)
		update(ss, mid, 2*si + 1, i, v);
	else
		update(mid+1, se, 2*si + 2, i, v);

	st[si] = st[2*si + 1]^st[2*si + 2];
}

bitset<M> query(int ss, int se, int si, int qs, int qe)
{
	if (se < qs or ss > qe)
		return 0;

	if (qs <= ss and qe >= se)
		return st[si];

	int mid = ss + (se - ss)/2;
	return query(ss, mid, 2*si + 1, qs, qe)^
		query(mid+1, se, 2*si + 2, qs, qe);
}

int main()
{
	TC()
	{
		memset(st, 0, sizeof(st));

		int a,b,c;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		
		constructST(0, n-1, 0);

		int q;
		cin >> q;

		for(int i=0; i<q; i++)
		{
			cin >> a >> b >> c;
			if (a == 0)
			{
				update(0, n-1, 0, b, 0);
				update(0, n-1, 0, c, 0);

				swap(arr[b], arr[c]);

				update(0, n-1, 0, b, 1);
				update(0, n-1, 0, c, 1);
			}
			else if(a == 1)
			{
				int ans=0;

				if (b<=c)
					ans = query(0, n-1, 0, b, c).count();
				else
				{
					auto tmp = query(0, n-1, 0, b, n-1)^query(0, n-1, 0, 0, c);
					ans = tmp.count();
				}

				cout << ans << "\n";
			}
		}
	}
	return 0;
}
