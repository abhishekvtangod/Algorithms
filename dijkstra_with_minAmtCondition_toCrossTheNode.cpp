/**
 *    author:  abhishekvtangod
 *    question: 
 				Given an undirected graph G having positive weights and N vertices.

				You start with having a sum of M money. For passing through a vertex i, you must pay S[i] money. 
				If you don’t have enough money – you can’t pass through that vertex. 
				Find the shortest path from vertex 1 to vertex N, respecting the above conditions; 
				or state that such path doesn’t exist. You start with having a sum of M money. For passing through a vertex i, you must pay S[i] money. 
				If you don’t have enough money – you can’t pass through that vertex. 
				Find the shortest path from vertex 1 to vertex N, respecting the above conditions; 
				or state that such path doesn’t exist. 
				If there exist more than one path having the same length, then output the cheapest one. 
				Restrictions: 1<N<=100 ; 0<=M<=100 ; for each i, 0<=S[i]<=100. 

				If there exist more than one path having the same length, then output the cheapest one. 
				Restrictions: 1<N<=100 ; 0<=M<=100 ; for each i, 0<=S[i]<=100. 

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

const int mxN = 100+6;
vector<int> v(mxN);
vector<int> cost(mxN);
int m, n, total;
// edges, vertices
vector<<pair

//use dijstra with 2d dist array; dist[i][j] denotes, min dist till ith node 
// and j money being left from initial money given.

void solve(){
	cin >> m >> n >> total;
	for(int i = 1;i <=n; i++){
		cin >> cost[i];
	}

	for(int i = 0 ; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;

	}
}


int main()
{   
	IOS;

 	#ifdef _ABHI
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
 

	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	

    return 0;
}