#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;

    multiset<int> hi;     
    multiset<int> lo;  
    long long sum_hi = 0; 
    long long total  = 0;  

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        total += x;

        lo.insert(x);

        int k = i / 2 + 1;

        while ((int)hi.size() < k) {
            auto it = prev(lo.end()); 
            int v = *it;
            lo.erase(it);
            hi.insert(v);
            sum_hi += v;
        }

        if (!hi.empty() && !lo.empty()) {
            auto it_hi_min = hi.begin();
            auto it_lo_max = prev(lo.end());
            if (*it_hi_min < *it_lo_max) {
                int a = *it_hi_min; 
                int b = *it_lo_max; 
                hi.erase(it_hi_min);
                lo.erase(it_lo_max);
                hi.insert(b);
                lo.insert(a);
                sum_hi += (long long)b - a;
            }
        }
    }

    cout << sum_hi << ' ' << (total - sum_hi) << '\n';
    return 0;
}
