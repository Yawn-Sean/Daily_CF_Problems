#include <iostream>
#include <vector>
#include <map>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    i64 a1, b1;
    i64 a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    auto cnt2 = [&](i64 x) {
        int res = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++res;
        }
        return res;
    };

    auto cnt3 = [&](i64 x) {
        int res = 0;
        while (x % 3 == 0) {
            x /= 3;
            ++res;
        }
        return res;
    };

    int v = cnt3(a1) + cnt3(b1) - cnt3(a2) - cnt3(b2);
    int num_op = 0;
    while (v < 0) {
        if (a2 % 3 == 0) {
            a2 = (a2 / 3) * 2;
        } else {
            b2 = (b2 / 3) * 2;
        }
        v++;
        num_op++;
    }

    while (v > 0) {
        if (a1 % 3 == 0) {
            a1 = (a1 / 3) * 2;
        } else {
            b1 = (b1 / 3) * 2;
        }
        v--;
        num_op++;
    }

    v = cnt2(a1) + cnt2(b1) - cnt2(a2) - cnt2(b2);

    while (v < 0) {
        if (a2 % 2 == 0) {
            a2 /= 2;
        } else {
            b2 /= 2;
        }
        v++;
        num_op++;
    }

    while (v > 0) {
        if (a1 % 2 == 0) {
            a1 /= 2;
        } else {
            b1 /= 2;
        }
        v--;
        num_op++;
    }

    if (1ll * a1 * b1 == 1ll * a2 * b2) {
        cout << num_op << '\n';
        cout << a1 << ' ' << b1 << '\n';
        cout << a2 << ' ' << b2 << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
