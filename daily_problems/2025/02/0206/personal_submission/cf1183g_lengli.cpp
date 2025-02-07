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
    std::cin>>n;
    std::vector<std::array<int,2>> a(n+2);
    for(int i=1;i<=n;i++){
        int x,c;
        std::cin>>x>>c;
        a[x][0]++,a[x][1]+=c;
    }

    sort(a.begin()+1,a.end()-1);

    std::priority_queue<int> q;

    int res=0,cnt=0;

    for(int i=n,idx=n;i>=1;i--){
        while(idx>=1 and a[idx][0]>=i){
            q.push(a[idx][1]);
            idx--;
        }
        if(q.size()){
            res+=i;
            cnt+=std::max(0,i-q.top());
            q.pop();
        }
    }
    std::cout<<res<<" "<<res-cnt<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
