#include <bits/stdc++.h>

using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
//constexpr int inf = 1e6;
constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vi p(n + 1);
    for(int i=1;i<=n;++i) cin>>p[i];
    i64 sum = 0,id = 0;
    int ge = 0,le = 0,eq = 0;
    unordered_map<int,int> cnt;
    for(int i=1;i<=n;++i){
        sum+=abs(p[i]-i);
        cnt[p[i]-i]++;
        if(p[i]>i) ge++;
        else if(p[i]==i) eq++;
        else le ++ ;
    }
    i64 tsum = sum;
    for(int i=1,last = n;i<=n;i++,last--){
        tsum += eq + le - ge - 1;
        eq = cnt[i];
        int d = abs(p[last]-1)-abs(p[last]-n);
        cnt[p[last]-last]--; cnt[p[last]-1 + i]++;
        tsum += d;
        if(p[last]>1) ge++;
        ge -= eq;
        le = n - ge - eq;
        if(tsum < sum) {
            sum = tsum;
            id = i;
        }
    }
    cout<<sum<<' '<<id;
}






