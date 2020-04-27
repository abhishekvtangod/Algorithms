/**
 *    author:  abhishekvtangod
 *    created: 27.04.2020 10:00:55 IST       
**/

#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;


#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };




void solve()
{
	ll n,x;cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
		cin>>x;
		v.push_back(x);
	}
	ll best=v[0],sum=v[0];
	
	for(ll i=1;i<n;i++)
	{
		sum = max(v[i],sum+v[i]);
		best = max(best,sum);
	}
	sum=0;
	ll cnt=0;
	
	unordered_map<ll,ll> prevSum;
	ll cursum=0;
	for(ll i=0;i<n;i++)
	{
		cursum+=v[i];
		
		if(cursum == best)
			cnt++;
		
		cnt+=prevSum[cursum-best];
		
		prevSum[cursum]++;
	}
	
	
	cout<<best<<" "<<cnt<<endl;
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}
