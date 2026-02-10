//Author: sandeep172918
//Date: 2026-02-10 11:22

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli long long int
#define fr(i,n) for(lli i=0;i<n;i++)
#define frs(i,a,b) for(lli i=a;i<=b;i++)
#define rfr(i,b,a) for(lli i=b;i>=a;i--)
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define pr pair<lli,lli>
#define vll vector<lli>
#define vbl vector<bool>
#define vpr vector<pr>
#define vvll vector<vector<lli>>
#define get(v,n) vll v(n);fr(i,n)cin>>v[i]
#define ff first
#define ss second
#define tr true
#define fs false
#define bitc(x) __builtin_popcountll(x)
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define psb(a) push_back(a)
#define ppb pop_back()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sq(x) sqrtl(x)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define no1 cout<<"-1\n"
#define nl cout<<endl
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
lli q(lli x,lli y){
    
    cout<<"? "<<x<<' '<<y<<'\n';
    lli a;
    cin>>a;
    cout.flush();

    return a;

} 


void solve(){
lli n,k;cin>>n;
lli ind=-1,ind2=-1;
fr(i,n){
    k=q(i,i);
    if(k==n){
      if(ind==-1)ind=i;
      ind2=i;
    }
}
    lli rem=-1;
    lli rem2=-1;
    fr(i,n){
        if(i!=ind2)rem=i;
        if(i!=ind)rem2=i;
    }
    k=q(ind,rem);
    lli k2=(ind2,rem2);
    if(k==n){
      cout<<"! "<<(ind2-ind+n)%n;
      nl;
      return;
    }else{
      cout<<"! "<<(ind-ind2+n)%n;
      nl;
      return;

    }
     if(k2==n){
      cout<<"! "<<(ind-ind2+n)%n;
      nl;
      return;
    }else{
      cout<<"! "<<(ind2-ind+n)%n;
      nl;
      return;

    }
    
}



int32_t main(){
lli test=1;
while(test--){
solve();
}
}

