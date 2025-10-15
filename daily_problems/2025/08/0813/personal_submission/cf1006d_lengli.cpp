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
    int n;
    std::string a,b;
    std::cin>>n>>a>>b;
    int res=0;
    for(int i=0;i<n/2;i++){
        std::map<char,int> q;
        q[a[i]]++,q[b[i]]++;
        q[a[n-i-1]]++,q[b[n-i-1]]++;
        if(q.size()==4) res+=2;
        else if(q.size()==3){
            if(a[i]==a[n-i-1]) res+=2;
            else res+=1;
        }else if(q.size()==2){
            if(q[a[i]]!=2) res++;
        }
    }

    if(n&1 and a[n/2]!=b[n/2]) res++;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
