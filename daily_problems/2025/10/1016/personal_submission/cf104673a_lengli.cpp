#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline int64 C2(int64 m){ return m*(m-1)/2; }
static inline int64 C3(int64 m){
    if(m<3) return 0;
    i128 v = (i128)m*(m-1)*(m-2)/6;
    if(v > (i128)LLONG_MAX) return LLONG_MAX;
    return (int64)v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int64 LIM = 1000000000LL;
    unordered_map<int64,int> bestRow; 
    bestRow.reserve(5000);

    for(int k=4; k<=60; ++k){ 
        i128 c = 1; 
        for(int m=k; ; ++m){
            if(c > LIM) break;
            if(c >= 2 && c <= LIM){
                int row = m + 1;
                auto it = bestRow.find((int64)c);
                if(it==bestRow.end()) bestRow[(int64)c] = row;
                else it->second = min(it->second, row);
            }

            int num = m+1, den = m+1-k;
            c = c * num / den;
            if(c > (i128)LIM && den==1) break; 
            if(m > 100000) break; 
        }
    }

    int Q; 
    if(!(cin >> Q)) return 0;
    while(Q--){
        int64 n; cin >> n;

        if(n==1){
            cout << 1 << '\n';
            continue;
        }

        int ans = (n >= 1 ? (int)(n + 1) : 1); 

        {
            long double d = 1.0L + 8.0L*(long double)n;
            int64 s = (int64)floor(sqrt(d) + 0.5L);
            while((s+1)*(s+1) <= 1 + 8*n) ++s;
            while(s*s > 1 + 8*n) --s;
            if(s*s == 1 + 8*n){
                if(((s + 1) & 1) == 0){ // (1+s) 偶数
                    int64 m = (1 + s) / 2;
                    if(m >= 2 && C2(m) == n) ans = min(ans, (int)(m + 1));
                }
            }
        }

        {
            long double approx = cbrt((long double)6.0L * (long double)n);
            int64 m0 = (int64)floor(approx);
            int64 lo = max<int64>(3, m0 - 10), hi = m0 + 10;
            for(int64 m=lo; m<=hi; ++m){
                if(C3(m) == n){
                    ans = min(ans, (int)(m + 1));
                    break;
                }
            }
        }

        auto it = bestRow.find(n);
        if(it != bestRow.end()) ans = min(ans, it->second);

        cout << ans << '\n';
    }
    return 0;
}
