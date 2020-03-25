// [abhishekvtangod]
// g++ -Wall -Wextra -Wshadow filename.cpp
#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;
ll *A;
ll *tree;
ll n;

void build(ll node, ll start, ll end)
{
    if(start == end)
    {
        tree[node] = A[start];
    }
    else
    {
        ll mid = start+(end-start)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node] = tree[2*node]+tree[2*node+1];
    }
    

}

void update(ll val,ll idx)
{
    A[idx]+=val;
    idx+=n;
    tree[idx]+=val;
    for(idx/=2;idx>=1;idx/=2)
        tree[idx]=tree[2*idx]+tree[2*idx+1];
}

ll sum(ll node,ll l,ll r, ll x, ll y)
{
    //complete outrange
    //complete inrange
    //partial in-partial out

    if(l > y || r < x) return 0;    //complete outrange
    if(l<=x && r>=y) return tree[node]; //complete inrange


    ll mid = x+(y-x)/2;

    //partial in-partial out
    return sum(2*node,l,r,x,mid)+sum(2*node+1,l,r,mid+1,y);


}
int main()
{   
    // ios::sync_with_stdio(false); 
    // cin.tie(nullptr);

    cin>>n;
    A = new ll[n];
    tree = new ll[2*n];
    for(ll i=0;i < n; i++)
    {
        cin>>A[i];
    }

    build(1,0,n-1);
    update(3,2);


    for(ll i =0; i <n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;

    for(ll i=1; i <2*n;i++)
        cout<<tree[i]<<" ";

    cout<<endl;


    cout<<"Range Query:\nEnter (l,r):\n";
    ll l,r;cin>>l>>r;
    cout<<sum(1,l,r,0,n-1)<<'\n';

    return 0;
}