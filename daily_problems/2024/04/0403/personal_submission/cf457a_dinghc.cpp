#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    s += "0000";
    t += "0000";

    int n = s.length(), m = t.length();

    int k = max(n, m);
    s = string(k - n, '0') + s;
    t = string(k - m, '0') + t;

    /*
      Compare digit by digit from high to low until there encounter digit 2 in either side, that is the bigger one.
      (the sum of all the q^i for i from 0 to n is smaller than twice q^(n+1):
        1 + q + q^2 + ... + q^n = (q^(n + 1) - 1) / (q - 1)
        because 1 / (q - 1) = q, so we have
        1 + q + q^2 + ... + q^n = (q^(n + 1) - 1) / (q - 1) = q * (q^(n + 1) - 1) 
           = q^(n + 2) - q = q^(n + 1) + q^n - q < 2 * q^(n + 1)
      )
    */
    int sgn = 0;
    for (int i = 0; i < k; i++) {
        char sc = s[i], tc = t[i];
        if (sc != tc) {
            if (sc == '1') {
                s[i + 1] += 1;
                s[i + 2] += 1;
                s[i + 1] -= t[i + 1] - '0';
                s[i + 2] -= t[i + 2] - '0';
                t[i + 1] = '0';
                t[i + 2] = '0';
                if (s[i + 1] == '2' || s[i + 2] == '2') {
                    sgn = 1;
                    break;
                }
            } else {
                t[i + 1] += 1;
                t[i + 2] += 1;
                t[i + 1] -= s[i + 1] - '0';
                t[i + 2] -= s[i + 2] - '0';
                s[i + 1] = '0';
                s[i + 2] = '0';
                if (t[i + 1] == '2' || t[i + 2] == '2') {
                    sgn = -1;
                    break;
                }
            }
        }
    }
    
    if (sgn == 0) {
        cout << "=";
    } else if (sgn > 0) {
        cout << ">";
    } else {
        cout << "<";
    }

    return 0;
}

