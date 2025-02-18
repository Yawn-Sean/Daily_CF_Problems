/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=1000010;

#define int long long

int sg[N];
std::map<int,int> cnt,q;


void solve(){
    sg[0]=1,sg[1]=0;
    int l=0,r=0;
    for(int i=2;i<N;i++){
        while(r*r<=i){
            cnt[sg[r]]++;
            r++;
        }
        while(l*l*l*l<i){
            cnt[sg[l]]--;
            l++;
        }
        while(cnt[sg[i]]) sg[i]++;
    }
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    sort(all(a));
    int res=0;
    l=0,r=0;
    for(auto i:a){
        if(i<N) res^=sg[i];
        else{
            while(r*r<=i){
                q[sg[r]]++;
                r++;
            }
            while(l*l*l*l<i){
                q[sg[l]]--;
                l++;
            }
            int t=0;
            while(q[t]) t++;
            res^=t;
        }
    }
    std::cout<<(!res ? "Rublo" : "Furlo")<<"\n";
} 

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
