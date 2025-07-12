#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cur = 0, cnt = 0, total = 0;
    while (n --) {
        int x;
        cin >> x;

        while (cur < x && cnt) {
            total += cnt & 1;
            cur ++;
            cnt >>= 1;
        }
        cur = x;
        cnt ++;
    }

    while (cnt) {
        total += cnt & 1;
        cur ++;
        cnt >>= 1;
    }

    cout << cur - total;

    return 0;
}
