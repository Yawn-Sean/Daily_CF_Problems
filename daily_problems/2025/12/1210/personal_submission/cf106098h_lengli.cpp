#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char ask(ll x) {
    cout << "? " << x << endl;
    cout.flush();
    char c;
    if (!(cin >> c)) {
        exit(0);
    }
    return c;
}

ll find_right_end(char base) {
    ll step = 1;
    while (true) {
        char c = ask(step);
        if (c != base) break;
        if (step > (ll)1e18 / 2) step = (ll)1e18;
        else step *= 2;
    }
    ll lo = step / 2; 
    ll hi = step;
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        char c = ask(mid);
        if (c == base) lo = mid;
        else hi = mid;
    }
    return lo;
}

ll find_left_end(char base){
    ll step = 1;
    while (true) {
        char c = ask(-step);
        if (c != base) break;
        if (step > (ll)1e18 / 2) step = (ll)1e18;
        else step *= 2;
    }
    ll lo = -step; 
    ll hi = -step/2; 
    while (lo + 1 < hi) {
        ll mid = lo + (hi - lo) / 2;
        char c = ask(mid);
        if (c == base) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        char base = ask(0);
        ll r = find_right_end(base);
        ll l = find_left_end(base);
        ll L = r - l + 1;
        if (L < 1) L = 1; 
        cout << "! " << L << endl;
        cout.flush();
    }
    return 0;
}
