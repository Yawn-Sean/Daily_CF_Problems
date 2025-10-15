#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (1ll * mid * (3ll * mid + 1) / 2 <= n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << (r + n % 3) / 3;

    return 0;
}
