//Author: sandeep172918
//Date: 2026-02-09 20:19

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
static inline lli mod_pow(lli a, lli e, lli m=MOD){
         lli r = 1 % m;
         a %= m;
         while(e){
             if(e & 1) r = (__int128)r * a % m;
             a = (__int128)a * a % m;
             e >>= 1;
         }
         return r;
     }
void solve(){
lli n,k;cin>>n;
string a,b,c;
cin>>a>>b>>c;
k=a.size();
lli tot=mod_pow(2,n-1);
lli ans=0;
fr(i,k){
    char aa=a[i];
    char bb=b[i];
    char cc=c[i];
    if(bb=='0'){
        if((aa-'0')  || (cc-'0')){
            cout<<"0\n";
            return;
        }
    }
    else{
        if(aa-'0'){
            if((n&1LL) != (cc-'0')){
                 cout<<"0\n";
                 return;
            }
        }else{ //and 0 aana chahiye or 1 mtlb atleast one 1 aur sare 1 nhi in competence with xor;
            if(cc-'0'){
               //xor 1 aana chahiye odd number of time
               ans=(ans+tot)%MOD;
               if(n&1LL)ans=(ans-1+MOD)%MOD;

            }else{
              // xor zero aana chaiye even number of time 
              ans=(ans+tot-1+MOD)%MOD;
              if((n&1LL) ==0 )ans=(ans-1+MOD)%MOD;

            }
           
        }
    }
}
cout<<ans<<'\n';

}

int32_t main(){
fastio;
lli test=1;
while(test--){
solve();
}
}
