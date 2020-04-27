/**
 *    author:  abhishekvtangod
 *    created: 16.04.2020 22:04:59 IST    
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


#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

//trie is matrix representation of trie data structure

//trie[k] represents list of links for the k-th node
//trie[k][m], node which represents son of k-th node using m-th character
ll tr[1000006][28];

ll root = 0;

void init()
{
	memset(tr,-1,sizeof(tr));
}
ll nxt = 1;

void insert(string s)
{
	ll node = root;
	
	for(ll i=0; i<s.size();i++)
	{
		ll q = s[i]-'a';
		
		if(tr[node][q] == -1)
		{
			tr[node][q] = nxt++;
		}
		
		node = tr[node][q];
	}
}


void solve()
{
	init();
	ll n,q;cin>>n>>q;
	for(ll i=0;i<n;i++)
	{
		string s;cin>>s;
		insert(s);
	}
	
	
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
