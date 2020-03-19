// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

void addEdge(vector<tuple<ll,ll,ll>>& edge_list,ll a,ll b,ll w)
{
    edge_list.push_back({a,b,w});
    edge_list.push_back({b,a,w});
}

void shortestPath(vector<tuple<ll,ll,ll>>& edge_list,vector<ll>& distance,ll n,ll edges)
{
    distance[1]=0;
    for(ll i=0;i<n;i++)
    {
        for(auto e: edge_list)
        {
            int a,b,w;
            tie(a,b,w) = e;
            distance[b] = min(distance[b],distance[a]+w);
        }
    }

}



int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    vector<tuple<ll,ll,ll>> edge_list;
    
    ll n,e;cin>>n>>e;
    ll a,b,w;
    for(ll i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        addEdge(edge_list,a,b,w);
    }
    vector<ll> distance(n+1,INFINITY);
    shortestPath(edge_list,distance,n,e);
    // for(auto u: edge_list)
    // {
    //     tie(a,b,w) = u;
    //     cout<<a<<" "<<b<<" "<<w<<endl;
    // }    
    for(ll i = 1; i<=n;i++ )
        cout<<distance[i]<<" ";


    return 0;
}


/*

    5
    7
    0 1 5
    0 3 7
    0 2 3
    1 3 3
    1 4 2
    2 3 1
    3 4 2

*/