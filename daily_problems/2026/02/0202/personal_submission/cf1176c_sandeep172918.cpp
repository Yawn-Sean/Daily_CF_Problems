//Author: sandeep172918
//Date: 2026-02-02 18:48

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
#define nl cout<<"\n"
#define out(v) fr(i,v.size())cout<<v[i]<<" ";nl
#define srtp(v) sort(all(v),[](const pr& a,const pr& b){if(a.ff== b.ff)return a.ss>b.ss; return a.ff<b.ff;});
using namespace std;
const int MOD=1e9+7;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

lli hi(lli x){
    if(x==4)return 0;
    if(x==8)return 1;
    if(x==15)return 2;
    if(x==16)return 3;
    if(x==23)return 4;
    if(x==42)return 5;
}


void solve(){
lli n,k;cin>>n;
get(v,n);
// map<lli,set<lli>>m;
// fr(i,n)m[hi(v[i])].insert(i);
// lli c=0;
// lli ans=0;
//  lli prev=-1;

// while(true){
//     vll t;
//     for(auto &it:m[c]){
//        if(it<prev){
//         t.psb(it);
//        }else{
//         break;
//        }
//     }
//     while(t.size()){
//         m[c].erase(t.back());
//         t.ppb;
//     }
    
//     if(m[c].size())
//     prev=*m[c].begin();
//     else break;
//     c++;
//     if(c==6){
//         c=0;
//         ans++;
//         prev=-1;
//     }

// }
// cout<<ans<<'\n';

vll cnt(6);
for(auto &it:v){
    lli x=hi(it);
    if(x==0)cnt[x]++;
    else{
        if(cnt[x-1]>cnt[x])cnt[x]++;
    }
}
cout<<n-6*cnt[5]<<'\n';
}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}
