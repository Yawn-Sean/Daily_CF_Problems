#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()




int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int mi = inf;
    while(m--){
        int l,r;cin>>l>>r;
        mi = min(mi,r-l+1);
    }
    cout<<mi<<endl;
    for(int i=0;i<n;++i)
        cout<<i%mi<<" \n"[i==n-1];
    return 0;

}
