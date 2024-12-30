#include <bits/stdc++.h>

//#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
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

//根号分治 O(p*B + p * n / B)=O(p*sqrt(n))
struct Qnode{
    int a,b,id;
    bool operator < (const Qnode& y){
        return b < y.b;
    }
};
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n,B;
    cin >> n;
    B  = sqrt(n);
    vi w(n);
    for(int i=0;i<n;++i) cin>>w[i];
    vl r(n);
    auto init = [&](int k){
        for(int i=n-1;i > n - 1 -k ;--i) r[i] = w[i];
        for(int i= n -1 - k;i >=0 ; --i) r[i] = w[i] + r[i+k];
    };
    int p;cin>>p;
    vector<Qnode> q(p);
    vl ans(p);
    for(int i=0;i<p;++i){
        cin>>q[i].a>>q[i].b;
        q[i].a--;
        q[i].id = i;
    }
    sort(all(q));
    for(int i=0;i<p;++i){
        int a = q[i].a,b = q[i].b;
        if(b > B){
            i64 s = 0;
            while(a < n) {
                s += w[a];
                a += b;
            }
            ans[q[i].id] = s;
        } else{
            if(i == 0 || q[i-1].b != b) init(b);
            ans[q[i].id] = r[a];
        }
    }
    for(auto a:ans)
        cout<<a<<endl;
}
