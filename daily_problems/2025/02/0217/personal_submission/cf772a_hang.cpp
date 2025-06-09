#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm> // for std::max

using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;
    vector<long long> inputs(n);
    vector<long long> stores(n);

    for (long long i = 0; i < n; ++i) {
        cin >> inputs[i] >> stores[i];
    }
    if (p >= accumulate(inputs.begin(), inputs.end(), 0LL)) {
        cout << -1 << endl;
        return 0;
    }
    long double l = 0, r = 1e18;
    long long iters = 0;
    while (iters < 220) {
        ++iters;
        long double mid = (l + r) / 2;
        long double tot = mid * p;
        long double needs = 0;
        for (long long i = 0; i < n; ++i) {
            needs += max(static_cast<long double>(inputs[i]) * mid - static_cast<long double>(stores[i]), 0.0L);
            //tot -= max(static_cast<long double>(inputs[i]) * mid - static_cast<long double>(stores[i]), 0.0L);
        }
        if (tot >= needs) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}