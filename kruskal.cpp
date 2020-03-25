// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;
vector<tuple<ll,ll,ll>> edge;

ll *link;
ll *siz;


ll find(ll x)
{
    while (x!=link[x])x=link[x];
    
    return x;
}

bool same(ll a, ll b)
{
    return find(a) == find(b);
}

void unite(ll a,ll b)
{
    a = find(a);
    b = find(b);
    if(siz[a]< siz[b]) swap(a,b);
    siz[a] += siz[b];
    link[b] = a;
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    
    ll u,v,w;
    for(ll i =0; i < m; i++)
    {
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    
    //phase 1
    //sorting based on weights
    sort(edge.begin(),edge.end(), [](tuple<ll,ll,ll>& t1,tuple<ll,ll,ll>& t2)->bool{ return (get<2>(t1) < get<2>(t2));});

    //phase 2
    //union-find structure
    link = new ll[n+1];
    siz = new ll[n+1];


    for(ll i =1;i <=n ; i++) link[i]=i;
    for(ll i =1;i <=n ; i++) siz[i]=1;
    


    return 0;
}
