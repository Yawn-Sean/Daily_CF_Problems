/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define aT(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

template<typename T>
struct Magic{
    T sl, sr;                 
    std::multiset<T> l, r;      
    Magic(){
        sl = sr = 0;
        l.clear(); r.clear();
    }
    void balance(){
        while (r.size() > l.size()){
            T v = *r.begin();
            r.erase(r.begin()); sr -= v;
            l.insert(v); sl += v;
        }
        while (l.size() > r.size() + 1){
            auto it = prev(l.end());
            T v = *it;
            l.erase(it); sl -= v;
            r.insert(v); sr += v;
        }
    }
    void insert(T x){
        if (l.empty() || x <= *prev(l.end())){
            l.insert(x); sl += x;
        } else {
            r.insert(x); sr += x;
        }
        balance();
    }
    void remove(T x){
        auto itl = l.find(x);
        if (itl != l.end()){
            l.erase(itl); sl -= x;
            balance();
            return;
        }
        auto itr = r.find(x);
        if (itr != r.end()){
            r.erase(itr); sr -= x;
            balance();
            return;
        }
    }
    T get_median() const {
        if (l.empty()) return (T)0;
        return *prev(l.end());
    }
    T cost() const {
        if (l.empty()) return 0;
        T m = (T)get_median();
        T left_cnt = (T)l.size();
        T right_cnt = (T)r.size();
        return m * left_cnt - sl + sr - m * right_cnt;
    }
};

void solve(){
    int n;
    i64 k;
    std::cin>>n>>k;
    std::vector<i64> a(n);
    for(auto &x:a) std::cin>>x;
    std::vector<i64> b(n);
    for(int i=0;i<n;i++) b[i]=a[i]-i;
    Magic<i64> M;
    int l=0,r=0;
    int res=1;
    while(r<n){
        M.insert(b[r]);
        while(l<=r and M.cost()>k){
            M.remove(b[l]);
            l++;
        }
        res=std::max(res,r-l+1);
        r++;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
