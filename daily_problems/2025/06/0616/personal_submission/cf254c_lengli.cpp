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
    std::string a,b;
    std::cin>>a>>b;
    std::vector<int> qa(26,0),qb(26,0);
    int n=a.size();
    for(int i=0;i<n;i++){
        qa[a[i]-'A']++;
        qb[b[i]-'A']++;
    }

    std::vector<int> cnt(26,0);

    int res=0;
    for(int i=0;i<n;i++){
        int v=a[i]-'A';
        if(qa[v]==qb[v]) continue;
        if(qa[v]>qb[v]){
            int idx=0;
            while(qa[idx]>=qb[idx]) idx++;
            if(v>idx){
                res++;
                qa[v]--;
                a[i]=idx+'A';
                v=a[i]-'A';
                cnt[v]++;
                qa[v]++;
            }else{
                if(cnt[v]+1<=qb[v]){
                    cnt[v]++;
                }else{
                    res++;
                    qa[v]--;
                    a[i]=idx+'A';
                    v=a[i]-'A';
                    cnt[v]++;
                    qa[v]++;
                }
            }
        }
    }

    std::cout<<res<<"\n";
    std::cout<<a<<"\n";
}

signed main(){
    fastio;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
