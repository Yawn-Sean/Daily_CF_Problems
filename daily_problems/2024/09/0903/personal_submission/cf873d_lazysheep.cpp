#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    if (k % 2 == 0) {
        cout << -1;
        return 0;
    }
    auto op = [&](auto &op, int l, int r) {
        if (!k || l + 1 == r) {
            return;
        }
        int m = l + r >> 1;
        swap(a[m - 1], a[m]);
        k--;
        op(op, l, m);
        op(op, m, r);
    };
    k /= 2;
    op(op, 0, n);
    if (k) {
        cout << -1;
    } else {
        for (int &x : a) {
            cout << x << ' ';
        }
    }
    return 0;
}
