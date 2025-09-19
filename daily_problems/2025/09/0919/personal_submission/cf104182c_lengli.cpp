#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n; vector<int> t;
    BIT(int n=0): n(n), t(n+1,0) {}
    void add(int i,int v){ for(; i<=n; i+=i&-i) t[i]+=v; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if(!(cin>>n)) return 0;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> p(n+1, n+1);
    {
        vector<int> st;
        for(int i=1;i<=n;i++){
            while(!st.empty() && a[st.back()] > a[i]){
                p[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }
    vector<int> q(n+1, 0);
    {
        vector<int> st;
        for(int i=1;i<=n;i++){
            while(!st.empty() && a[st.back()] <= a[i]) st.pop_back();
            q[i] = st.empty() ? 0 : st.back();
            st.push_back(i);
        }
    }
    vector<vector<int>> addAt(n+2);
    for(int l=1;l<=n;l++) if(p[l] <= n) addAt[p[l]].push_back(l);

    BIT bit(n);
    long long ans = 1;               
    for(int r=1;r<=n;r++){
        for(int l : addAt[r]) bit.add(l, 1);    
        ans += bit.sum(q[r]);                   
    }

    cout << ans << '\n';
    return 0;
}
