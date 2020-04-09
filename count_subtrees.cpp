
// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;
//bool *visited;
vector<ll> *adj;
ll *cnt;		

void addEdge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs_tree(ll s,ll parent)
{
		cnt[s] = 1;
		for(auto u:adj[s])
		{
			if(u != parent)
			{
				
				dfs_tree(u,s);
				cnt[s] += cnt[u];
			}
		}
}



int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
	
	
	ll t;cin>>t;
	
	while(t--)
	{
		ll n;cin>>n;
		
		adj = new vector<ll>[n+1];
		
		ll u,v;
		for(ll i=0; i < n-1;i++)
		{
			cin>>u>>v;
			addEdge(u,v);
			
		}
		//visited = new bool[n+1];
		//memset(visited,false,n+1);
		cnt = new ll[n+1];
		//memset(cnt,0,n+1);
		dfs_tree(1,-1);
		

		
		for(ll i=1; i <= n;i++)
			cout<<cnt[i]<<" ";

		//for(ll i=0; i < n-1;i++)
		//{
			//cout<<i<<"->";
			//for(auto tmp:adj[i])
				//cout<<tmp<<" ";
			//cout<<endl;
		//}

	}
	
	

    return 0;
}
