#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    i64 w,m,k;
    cin >> w >> m >> k;


    i64 base10 = 1;
    i64 mLen = 0;
    while (base10 <= m) {
        base10 *= 10;
        mLen++;
    }

    i64 ans = 0;
    i64 sameLenCount = base10 - m; // 和m同长度的数字个数
    i64 actual = min(sameLenCount, w / (k * mLen));
    ans += actual;
    w -= actual * k * mLen;

    while (w > 0) {
        mLen++;

        i64 count = base10 * 10 - base10;
        i64 actual = min(count, w / (k * mLen));
        ans += actual;
        w -= actual * k * mLen;

        base10 *= 10;
        if (actual == 0) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
