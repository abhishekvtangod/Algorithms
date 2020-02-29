// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

void addEdge(vector<ll> adj[],ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void dfs(bool visited[],vector<ll> adj[],ll v)
{   
    if(visited[v] == true) return;

    visited[v] = true;
    cout<<v<<" ";
    for(ll i = 0; i < adj[v].size(); i++)
    {
        dfs(visited,adj,adj[v][i]);
    }
    
}

int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n,m,u,v;
    cin>>n>>m;
    vector<ll> adj[n];
    bool visited[n]={false};    
    for(ll i = 0; i < m; i++)
    {
        cin>>u>>v;
        addEdge(adj,u,v);
    }    

    dfs(visited,adj,0);
    return 0;
}