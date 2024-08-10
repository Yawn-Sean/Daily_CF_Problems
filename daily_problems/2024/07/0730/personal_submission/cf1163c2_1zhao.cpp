#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > poles(n);
    for(int i=0; i<n; i++) cin >> poles[i].first >> poles[i].second;

    long long res = 0;

    unordered_map<long long, unordered_set<long long > > wires;
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            pair<int, int> k = {poles[i].first - poles[j].first, poles[i].second - poles[j].second};
            int d = __gcd((unsigned)abs(k.first), (unsigned)abs(k.second));
            if(k.first == 0) d = k.second;
            if(k.second == 0) d = k.first;
            if(d * k.first < 0) d = -d;
            if(d == 0) d = 1;
            k.first /= d;
            k.second /= d;

            pair<int, int> b = {poles[i].first * k.second - poles[i].second * k.first, k.second};
            d = __gcd((unsigned)abs(b.first), (unsigned)abs(b.second));
            if(b.first == 0) d = b.second;
            if(b.second == 0) d = b.first;
            if(d * b.first < 0) d = -d;
            if(d == 0) d = 1;
            b.first /= d;
            b.second /= d;

            if(k.second == 0) {
                b.first = poles[i].second;
            }

            long long k_code = (long long)k.first * 100000 + k.second;
            long long b_code = (long long)b.first * 100000 + b.second;

            if(!wires[k_code].count(b_code)) {
                cnt ++;
                wires[k_code].insert(b_code);
                res += cnt - wires[k_code].size();
            }
        }
    }

    cout << res << endl;
}
