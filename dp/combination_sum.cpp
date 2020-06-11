/**
 *    author:  abhishekvtangod
 *    created:        
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


ll dp[1000006];

void solve()
{
	ll n,k;cin>>n>>k;
	memset(dp,0,sizeof(dp));
	vector<ll> v;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		v.push_back(x);
	}
	dp[0]=1;
	for(ll i=1;i<=k;i++)
	{
		for(int x:v)
		{
			if(i-x>=0)
			dp[i]+=dp[i-x];
			
		}
	}
	for(int i=0;i<=k;i++)
	{
		cout<<dp[i]<<" ";
	}
		cout<<endl;
	
	cout<<dp[k]<<endl;
	
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	//ll t;cin>>t;
	//while(t--)
	//{
		solve();
	//}
	

    return 0;
}
