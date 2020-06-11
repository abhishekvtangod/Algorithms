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


#ifndef _DEBUG
	freopen("inputf.txt", "r", stdin);
//	freopen("outputf.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

ll n;
ll dp[10006][10006];
vector<ll> v;

ll profit(ll i,ll j)
{
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
		
	ll yr = n-(j-i);
	return dp[i][j] = max(profit(i+1,j)+yr*v[i],profit(i,j-1)+yr*v[j]);
}


void solve()
{
	cin>>n;
	v.resize(n+2);
	for(ll i =1;i<=n;i++)
	{
		cin>>v[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<profit(1,n)<<endl;
	//for(ll i=1;i<=n;i++)
	//{
		//for(ll j=1;j<=n;j++)
			//cout<<dp[i][j]<<" ";
		//cout<<endl;
	//}

	
		
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
