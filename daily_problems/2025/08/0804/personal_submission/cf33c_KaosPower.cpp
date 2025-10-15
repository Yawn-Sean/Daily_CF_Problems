//  C. Wonderful Randomized Sum

#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int dp1 = 0, dp2 = 0, dp3 = 0;

    while (n --) {
        int x;
        cin >> x;

        dp3 = max(dp2, dp3) - x;
        dp2 = max(dp1, dp2) + x;
        dp1 -= x;
    }

    cout << max(dp2, dp3);

    return 0;
}
