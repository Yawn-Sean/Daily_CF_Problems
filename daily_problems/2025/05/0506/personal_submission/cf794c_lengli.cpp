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
    sort(all(a));
    sort(all(b),std::greater<>());

    std::deque<int> qa,qb;

    int n=a.size();

    for(int i=0;i<(n+1)/2;i++) qa.pb(a[i]);
    for(int i=0;i<n/2;i++) qb.pb(b[i]);

    std::vector<char> res(n);
    int l=0,r=n-1;
    for(int i=1;i<=n;i++){
        if(i&1){
            if(qa.front()>=qb.front()){
                res[r]=qa.back();
                qa.pop_back();
                r--;
            }else if(qa.front()<=qb.front()){
                res[l]=qa.front();
                qa.pop_front();
                l++;
            }
        }else{
            if(qb.front()<=qa.front()){
                res[r]=qb.back();
                qb.pop_back();
                r--;
            }else if(qb.front()>=qa.front()){
                res[l]=qb.front();
                qb.pop_front();
                l++;
            }
        }
    }
    for(auto x:res) std::cout<<x;
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
