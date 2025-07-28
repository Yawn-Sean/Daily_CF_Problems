#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 998244353;
const int N = 2e5 + 1, M = 350;

void solve() {
    int n;
    cin >> n;
    std::vector<int> ve(n);
    for(int i=0; i<n; i++){
        cin>>ve[i];
    }
    vector<int>a(n,0);
    bool ok=false;
    for(int i=1; i<n; i++){
        if(ve[i-1]>ve[i]) ok=true;

    }
    if(!ok){
        cout<<0<<endl;
        return ;
    }
    vector<int>stk;
    vector<int>dp(n,0);
    int ans=0;
    for(int i=n-1; i>=0; i--){
        int temp=0;
        while(!stk.empty() && ve[i]>ve[stk.back()]){
            temp=max(dp[stk.back()],temp+1);
            stk.pop_back();
        }
        ans=max(ans,temp);
        dp[i]=temp;
        stk.push_back(i);
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init();
    int t = 1;
    //cin >> t;
    while (t--)solve();
    return 0;
}
