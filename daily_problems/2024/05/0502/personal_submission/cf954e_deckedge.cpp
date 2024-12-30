#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), t = red();
    vector<pi> a(n);
    double low = 0;
    double high = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i].se; 
        high += a[i].se;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
    }

    sort(all(a));
    auto check = [&](double flow){
        double cur, s = 0, mx = 0, mn = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur = min(flow - s, (double)a[i].se);
            mx += cur * a[i].fi;
            s += cur;
        }
        s = 0;
        for (int i = 0; i < n; i++) {
            cur = min(flow - s, (double)a[i].se);
            mn += cur * a[i].fi;
            s += cur;
        }
        return (mn <= t * flow && t * flow <= mx);
    };

    for (int i = 0; i < 200; i++) {
        double mid = (low + high + 1) / 2;

        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << fixed << setprecision(10) << low << '\n';

    return 0;
}

