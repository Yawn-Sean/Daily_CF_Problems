#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin >> a;

    int n = a.length();
    
    int freq[10]{};
    for (auto& d : a) {
        freq[d - '0']++;
    }
    
    freq[1]--;
    freq[8]--;
    freq[6]--;
    freq[9]--;
    
    n -= freq[0];
    int k = n % 3;
    int g = n / 3;
    int r = 0;
    int d = 1;
    string ans;
    int sgn = ((n + 2) / 3) % 2 == 1 ? 1 : -1;
    for (int i = 0; i < k; i++) {
        while (d < 10 && freq[d] == 0) d++;
        if (d == 10) {
            r = (r * 10 + 0) % 7;
        } else {
            r = (r * 10 + d) % 7;
            freq[d]--;
            ans += d + '0';
        }
    }
    r = (7 + sgn * r) % 7;

    for (int i = 0; i < g - 1; i++) {
        sgn = -sgn;
        int t = 0;
        for (int i = 0; i < 3; i++) {
            while (d < 10 && freq[d] == 0) d++;
            if (d == 10) {
                t = (t * 10 + 0) % 7;
            } else {
                t = (t * 10 + d) % 7;
                freq[d]--;
                ans += d + '0';
            }
        }
        r = (r + 7 + sgn * t) % 7;
    }
    
    auto f = [&] (int r, int sgn) {
        int d[4] {1,8,6,9};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i != j && i != k && j != k) {
                        int r1 = (d[i] * 100 + d[j] * 10 + d[k]) % 7;
                        for (int h = 0; h < 4; h++) {
                            if (h != i && h != j && h != k) {
                                int diff = (d[h] + 7 - r1) % 7;
                                if ((r + 7 + sgn * diff) % 7 == 0) {
                                    ans += d[h] + '0';
                                    ans += d[i] + '0';
                                    ans += d[j] + '0';
                                    ans += d[k] + '0';
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    };
    
    f(r, sgn);
    
    cout << ans + string(freq[0], '0') << "\n";

    return 0;
}
