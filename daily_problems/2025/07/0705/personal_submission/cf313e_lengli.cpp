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
    int n,m;
    std::cin>>n>>m;

    std::vector<int> a(m+2),b(m+2),k(m+2);

    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[x]++;
    }
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        b[m-x-1]++;
    }

    std::stack<int> s;

    for(int i=0;i<m;i++){
        while(a[i]) s.push(i),a[i]--;
        while(b[i] and s.size()){
            k[(s.top()+m-i-1)%m]++;
            b[i]--;
            s.pop();
        }
    }  
    for(int i=0;i<m;i++){
        while(a[i]) s.push(i),a[i]--;
        while(b[i] and s.size()){
            k[(s.top()+m-i-1)%m]++;
            b[i]--;
            s.pop();
        }
    }  
    for(int i=m-1;i>=0;i--){
        while(k[i]--) std::cout<<i<<" ";
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
