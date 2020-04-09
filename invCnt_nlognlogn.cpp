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
//typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> is;
#define ar array

int n, a[200000];
void solve()
{
	cin>>n;
	for(ll i=0; i<n; i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	oset<ar<int, 2>> s;
	//for(int i=n-1; i>=0; i--) {
		//ans+=s.order_of_key({a[i], -1});
		//cout<<ans<<" "<<i<<endl;
		//s.insert({a[i], i});
	//}
	
	//or

	for(int i=0; i<n; i++) {
		ans+=(s.order_of_key({-a[i], -1}));
		s.insert({-a[i], i});
	}
	cout << ans%mod<<'\n';
}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	ll t;cin>>t;
	while(t--)
	{
		solve();
	}
	

    return 0;
}
