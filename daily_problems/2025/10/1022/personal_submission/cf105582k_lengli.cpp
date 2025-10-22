#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<pair<int,int>> base;
    for (int m = 2; m <= 80 && (int)base.size() < 50; ++m) {
        for (int k = 1; k < m && (int)base.size() < 50; ++k) {
            if (std::gcd(m,k) != 1) continue;
            if ( ( (m - k) & 1 ) == 0 ) continue; 
            long long a = 1LL*m*m - 1LL*k*k;  
            long long b = 2LL*m*k;         
            if (a==0 || b==0) continue;
            if (a > 200 || b > 200) continue;
            base.push_back({(int)a,(int)b});
        }
    }

    vector<pair<int,int>> vecs;

    if (n % 2 == 0) {
        int need = n / 2;
        for (int i = 0; i < need; ++i) {
            auto [a,b] = base[i];
            vecs.push_back({ a,  b});
            vecs.push_back({-a, -b});
        }
    } else {
        int pairs = (n - 3) / 2;
        for (int i = 0; i < pairs; ++i) {
            auto [a,b] = base[i];
            vecs.push_back({ a,  b});
            vecs.push_back({-a, -b});
        }
        vecs.push_back({  4,   3});
        vecs.push_back({-24,  18});
        vecs.push_back({ 20, -21});
    }

    sort(vecs.begin(), vecs.end(), [](auto L, auto R){
        return atan2((double)L.second, (double)L.first) <
               atan2((double)R.second, (double)R.first);
    });

    vector<pair<long long,long long>> pts;
    long long x = 0, y = 0;
    for (auto [a,b] : vecs) {
        pts.push_back({x, y});
        x += a; y += b;
    }

    for (auto [px,py] : pts) {
        cout << px << ' ' << py << "\n";
    }
    return 0;
}
