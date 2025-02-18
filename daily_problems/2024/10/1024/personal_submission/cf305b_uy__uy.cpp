#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    i64 p, q;
    cin >> p >> q;
    int n;
    cin >> n;
    vector<i64>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<i64>b;
    while (q) {
        b.push_back(p / q);
        p %= q;
        swap(p, q);
    }
    // for (auto x : b) {
    //     cerr << x << " ";
    // }
    if (a.size() > 1 && a.back() == 1) {
        a.pop_back();
        a.back()++;
    }
    if (b.size() != a.size()) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < b.size(); i++) {
        if (a[i] != b[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
