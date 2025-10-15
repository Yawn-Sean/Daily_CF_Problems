

#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    while (n --) {
        int k, a;
        cin >> k >> a;

        ans = max(ans, k + 1);
        while (a > 1) {
            a = (a + 3) / 4;
            k ++;
        }

        ans = max(ans, k);
    }

    cout << ans;

    return 0;
}
