/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    
    i64 res=inf;

    {
        std::priority_queue<int> q,tmp;
        std::vector<int> idx(n+2);
        for(int i=1;i<=n;i++) q.push(a[i]);
        for(int i=n;i>=1;i--){
            if(q.top()==a[i]) q.pop();
            else tmp.push(a[i]);
            while(tmp.size() and q.size()){
                if(tmp.top()==q.top()){
                    tmp.pop();
                    q.pop();
                }else break;
            }
            if(q.size()==i-1){
                int j=i-1;
                while(j>=1){
                    if(a[j]==q.top()) q.pop(),j--;
                    else break;
                }
                j++;
                for(int t=i;t>=j;t--) idx[t]=q.size();
                i=j;
            }
            idx[i]=q.size();
        }
        for(int i=1;i<=n;i++){
            i64 v=1ll*(n-i+1)*(n-i+1)+1ll*idx[i]*idx[i];
            res=std::min(res,v);
        }
    }

    {
        std::priority_queue<int,std::vector<int>,std::greater<>> q,tmp;
        std::vector<int> idx(n+2);
        for(int i=1;i<=n;i++) q.push(a[i]);
        for(int i=1;i<=n;i++){
            if(q.top()==a[i]) q.pop();
            else tmp.push(a[i]);
            while(tmp.size() and q.size()){
                if(tmp.top()==q.top()){
                    tmp.pop();
                    q.pop();
                }else break;
            }
            if(q.size()==n-i){
                int j=i+1;
                while(j<=n){
                    if(a[j]==q.top()) q.pop(),j++;
                    else break;
                }
                j--;
                for(int t=i;t<=j;t++) idx[t]=q.size();
                i=j;
            }
            idx[i]=q.size();
        }
        for(int i=1;i<=n;i++){
            i64 v=1ll*i*i+1ll*idx[i]*idx[i];
            res=std::min(res,v);
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
