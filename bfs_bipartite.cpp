// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
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

vector<ll> adj[1000006];
ll side[1000006];
ll n;


bool bfs_bipartite(ll x)
{
	queue<ll> q;
	q.push(x);
	side[x]=1;
	while(!q.empty())
	{
		ll s = q.front();q.pop();
		
		for(auto u:adj[s])
		{
			if(!side[u])
			{
				side[u] = -side[s];
				q.push(u);
			}
			else if(side[u] == side[s])
				return false;
		}
		
		
		
	}
	
	return true;
}


void solve()
{
	
	ll e;cin>>n>>e;
	for(ll i=0;i<n+2;i++)adj[i].clear(),side[i]=0;
	
	for(ll i=0;i < e;i++)
	{
		ll u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	ll flag =1;
	for(ll i=1; i <=n ; i++)
	{
		if(!side[i])
		{
			if(!bfs_bipartite(i))
				flag=0;
		}
	}
	
	
	cout<<((flag)?"Yes,Bipartite":"No,Not-Bipartite");

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
