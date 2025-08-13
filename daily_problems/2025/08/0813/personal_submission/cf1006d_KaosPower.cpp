#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;

    for (int i = 0; i < n / 2; i ++) {
        char a = s1[i], b = s1[n - 1 - i], c = s2[i], d = s2[n - 1 - i];
        if ((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
            ans += 0;
        else if (a == c || a == d || b == c || b == d || c == d)
            ans += 1;
        else
            ans += 2;
    }

    if (n & 1) ans += s1[n / 2] != s2[n / 2];

    cout << ans;

    return 0;
}
