#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.length();
        int pre0 = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int maxlen = 18;
            if (str[i] == '0') {
                pre0++;
            } else {
                int r = i;
                int sum = 1;
                while (maxlen--) {
                    if (sum <= pre0 + r - i + 1) {
                        ans++;
                    }
                    if (r + 1 == n) {
                        break;
                    } else {
                        sum = sum * 2 + (str[++r] - '0');
                    }
                }
                pre0 = 0;
            }
        }
        cout << ans << endl;
    }
}