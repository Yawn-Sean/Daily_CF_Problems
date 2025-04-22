#include <bits/stdc++.h>
 
using namespace std;

int main() {
    array<int, 2> a, b;
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    array<long long, 2> p{1LL * a[0] * a[1], 1LL * b[0] * b[1]};
    array<int, 2> f2{}, f3{};
    for (int i = 0; i < 2; i++) {
        while (p[i] % 2 == 0) {
            p[i] /= 2;
            f2[i] += 1;
        }
        while (p[i] % 3 == 0) {
            p[i] /= 3;
            f3[i] += 1;
        }
    }
    auto div3 = [] (array<int, 2>& arr, int k) {
        while (k) {
            if (arr[0] % 3 != 0) {
                while (k) {
                    arr[1] /= 3;
                    arr[1] <<= 1;
                    k -= 1;
                }
                break;
            }
            arr[0] /= 3;
            arr[0] <<= 1;
            k -= 1;
        }
    };
    auto div2 = [] (array<int, 2>& arr, int k) {
        while (k) {
            if (arr[0] % 2 != 0) {
                while (k) {
                    arr[1] /= 2;
                    k -= 1;
                }
                break;
            }
            arr[0] /= 2;
            k -= 1;
        }
    };
    if (p[0] != p[1]) {
        cout << "-1\n";
    } else {
        int ans = 0, k;
        if (f3[0] > f3[1]) {
            k = f3[0] - f3[1];
            div3(a, k);
            f2[0] += k;
            ans += k;
        } else {
            k = f3[1] - f3[0];
            div3(b, k);
            f2[1] += k;
            ans += k;
        }
        if (f2[0] > f2[1]) {
            k = f2[0] - f2[1];
            div2(a, k);
            ans += k;
        } else {
            k = f2[1] - f2[0];
            div2(b, k);
            ans += k;
        }
        cout << ans << "\n";
        cout << a[0] << " " << a[1] << "\n";
        cout << b[0] << " " << b[1] << "\n";
    }
    return 0;
}

