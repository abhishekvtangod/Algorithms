// Given v cities connected by e bidirectional roads with w distance each, 
// there are x cities among them which have stadiums. 
// Find out the nearest city which has stadium and print its distance from the city, for each city.

/**
 *    author:  abhishekvtangod
**/
// #undef _GLIBCXX_DEBUG
// #undef _ABHI
#include<bits/stdc++.h>
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

void debug_out() { cerr << "]" << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << H << ", ";
  debug_out(T...);
}

#ifdef _GLIBCXX_DEBUG
#define debug(x...) cerr << "[" << #x << "]:[", debug_out(x)
#else
#define debug(...) 42
#endif

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

const int mxN = 1e5+6;
int e, n, st;
vector<pair<int, ll>> adj[mxN];
vector<int> stdm;
ll dist[mxN];

void init(){
	stdm.clear();
	for(auto &u: dist){
		u = (1LL<<62);
	}
	for(auto &u: adj){
		u.clear();
	}
}

void dijkstra(){
	set<pair<ll, int>> pq;
	for(auto u: stdm){
		pq.insert({0, u});
		dist[u] = 0;
	}

	while(!pq.empty()){
		int src = pq.begin()->second;
		pq.erase(*pq.begin());

		for(auto u: adj[src]){
			if(dist[src] + u.second < dist[u.first]){
				pq.erase({dist[u.first], u.first});
				dist[u.first] = dist[src] + u.second;
				pq.insert({dist[u.first], u.first});
			}
		}
	}

	// for(int i = 1; i<=n; i++){
	// 	debug(i, dist[i]);
	// }

}

void solve(){
	init();
	cin >> n >> e;
	cin >> st;
	for(int i = 0 ; i < st; i++){
		int temp;
		cin >> temp; 
		stdm.push_back(temp);
	}
	map<pair<int, int>, ll> mp;
	for(int i = 0; i < e; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		if(u > v){
			swap(u, v);
		}		
		if(!mp[{u, v}]){
			mp[{u, v}] = w;
		} else{
			mp[{u, v}] = min({mp[{u, v}], w});
		}
	}
	for(auto it: mp){
		int u = it.first.first, v = it.first.second;
		ll w = it.second;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra();
	for(int i = 1; i<=n; i++){
		cout << i << " " << dist[i] << endl;
	}



}


int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
 

	ll t;cin>>t;
	while(t--){
		solve();
	}
	

    return 0;
}