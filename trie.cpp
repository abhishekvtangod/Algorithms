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

struct Trie
{
	bool isEndOfWord;
	unordered_map<char,Trie*> map;
	
};

Trie* getNewTrieNode()
{
		Trie* node = new Trie;
		node->isEndOfWord=false;
		return node;
}

void insert(Trie*& root,string str)
{
	if(root == nullptr)
		root = getNewTrieNode();
	Trie* temp = root;
	
	for(ll i=0;i < (ll)str.size();i++)
	{
		char x = str[i];
		
		if(temp->map.find(x) == temp->map.end())
			temp->map[x] = getNewTrieNode();
		
		
		temp=temp->map[x];
	}
	temp->isEndOfWord = true;
	
	
}
bool search(Trie* root,string s)
{
	if(root == nullptr)
		return false;
		
	Trie* temp=root;
	
	for(ll i=0;i<(ll)s.size();i++)
	{
		temp=temp->map[s[i]];
		
		if(temp == nullptr)
			return false;
	}
	return temp->isEndOfWord;
	
	
}

void solve()
{
		Trie* root=nullptr;
		//ll n;cin>>n;
		//for(ll i=0; i< n ; i++)
		//{
			//string oper,s;
			//cin>>oper>>s;

			//if(oper == "add")
			//{
				//insert(root,s);
			//}
			//else if(oper == "find")
			//{

				//cout<<search(root,s)<<endl;
			//}
		//}

		
		//insert(root,"abhi");
		//insert(root,"abhish");
		//insert(root,"abhishek");
		//insert(root,"tangod");
		//insert(root,"abhishektangod");
		
		//cout<<search(root,"abhishek")<<'\n'<<search(root,"tangod")<<endl;
		//cout<<search(root,"abhishektang")<<endl;



		//insert(root,"lzrxegypcyyyjfszwrdu");
		//cout<<search(root,"bomdf");
		//insert(root,"davhhsqnbhceblqqfbgk");
		//cout<<search(root,"o");
		//insert(root,"jodauvovxhcgokyvkiou");
		//cout<<search(root,"vgwt");
		//insert(root,"ssnhyzskrfeveypkaqcn");
		//cout<<search(root,"vkuox");
		//insert(root,"ksjdjumtnpybbzivjbaw");
		//cout<<search(root,"w");
		//insert(root,"swloaeievbbqtnungxej");
		//cout<<search(root,"uf");
		//insert(root,"olmcezklmotysqoumlld");



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
