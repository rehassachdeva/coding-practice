class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
  	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
  	pq.push(1);
  	for (auto& p : primes)
  	pq.emplace(p);
	long long int ret;
  	for (int i=0; i<n; i++)
  	{
  		ret = pq.top(); pq.pop();
  		for (int i=0; i<primes.size(); i++)
  		{
  			if (ret%primes[i]==0)
  			{
  				for (int j=0; j<=i; j++)
  					pq.emplace(ret*primes[j]);
  				break;
  			}
  		}
  	}
  	return ret;
    }
};