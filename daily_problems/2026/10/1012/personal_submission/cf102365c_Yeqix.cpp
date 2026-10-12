#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int query(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void print(int x) {
    cout << "! " << x << "\n";
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pre = 2;
    for (int i = 3; i <= n; i++) {
        if (query(1, pre, i)) {
            pre = i;
        }
    }

    print(pre);
    return 0;
}