// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

void addEdge(vector<pair<ll,ll>> adj[],ll a,ll b,ll w)
{
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
}

void shortestPath(vector<pair<ll,ll>> adj[],vector<ll>& distance,ll n,ll edges)
{
    priority_queue<pair<ll,ll>> q;
    bool processed[n];
    memset(processed,false,n);
    distance[0]=0;
    q.push({0,1});
    while(!q.empty())
    {
        ll a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u:adj[a])
        {
            ll b = u.first, w=u.second;
            if(distance[a]+w < distance[b])
            {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
    

}



int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    ll n,e;cin>>n>>e;
    vector<pair<ll,ll>> adj[n];


    ll a,b,w;
    for(ll i=0;i<e;i++)
    {
        cin>>a>>b>>w;
        addEdge(adj,a,b,w);
    }
    // vector<ll> distance(n,INFINITY);
    // shortestPath(adj,distance,n,e);
    for(auto u: adj[1])
    {
        cout<<u.first<<" "<<u.second<<endl;
    }    
    // for(auto u:distance)
    //     cout<<u<<" ";


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