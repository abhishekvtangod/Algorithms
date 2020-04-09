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
bool visited[1000006];
ll color[1000006];

bool isBipartite(ll x)
{
	visited[x]=true;
	for(auto u:adj[x])
	{
		if(!visited[u])
		{
				color[u] = !color[x];
				if(!isBipartite(u))
					return false;
				
		}
		else if(color[u] == color[x])
			return false;
	}
	
	return true;
}


void solve()
{
	ll n,e;cin>>n>>e;
	for(ll i=0;i<n+2;i++)adj[i].clear(),visited[i]=false,color[i]=0;
	
	for(ll i=0;i < e;i++)
	{
		ll u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	
	
	color[1]=0;
	ll flag =0;
	for(ll i=1; i <=n;i++)
	{
		if(!visited[i])
		{
			if(!isBipartite(i))
			{
				flag=1;
				break;
			}
		}
	}
	
	cout<<((!flag)?"Yes,Bipartite!\n":"No,Not Bipartite\n");
}



int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	//ll t;cin>>t;
	//ll i=1;
	//while(t--)
	//{
		//cout<<"Scenario #"<<i<<":\n";
		solve();
		//i++;
	//}
	

    return 0;
}
