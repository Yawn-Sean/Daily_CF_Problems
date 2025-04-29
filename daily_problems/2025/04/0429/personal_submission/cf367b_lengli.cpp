/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m,p;
    std::cin>>n>>m>>p;
    std::vector<std::vector<int>> a(p);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[i%p].pb(x);
    }
    std::map<int,int> cnt_b;
    for(int i=0;i<m;i++){
        int x;
        std::cin>>x;
        cnt_b[x]++;
    }
    int len=cnt_b.size(),k=0;

    std::vector<int> res;

    for(int t=0;t<p;t++){
        auto &s=a[t];
        int tmp=s.size();
        if(tmp<m) continue;
        k=0;
        std::map<int,int> cnt_a;

        auto add=[&](int x){
            cnt_a[x]++;
            if(cnt_a[x]==cnt_b[x]) k++;
            else if(cnt_a[x]==cnt_b[x]+1) k--;
        };
        auto del=[&](int x){
            cnt_a[x]--;
            if(cnt_a[x]==cnt_b[x]) k++;
            else if(cnt_a[x]==cnt_b[x]-1) k--;
        };

        int st=t;
        for(int i=0;i<m-1;i++) add(s[i]);
        for(int i=m-1,j=0;i<tmp;i++,st+=p){
            add(s[i]);
            while(i-j+1>m){
                del(s[j]);
                j++;
            }
            if(k==len) res.pb(st);
        }
    }
    std::cout<<res.size()<<"\n";
    sort(all(res));
    for(auto x:res) std::cout<<x+1<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
