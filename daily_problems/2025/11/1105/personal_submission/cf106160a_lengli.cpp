#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s; 

    int k = s.size();
    long double ans = 0.0L;
    long double val = 0.0L;
    long double cur = 1.0L;

    for (int i = 0; i < k - 1; i++) {
        int digit = s[i] - '0';
        val += digit * cur;
        ans += val;
        cur /= 10.0L;
    }

    int last_digit = s.back() - '0';
    val += last_digit * cur;

    long double res = ans * 0.9L + val;

    cout << fixed << setprecision(20) << (double)res << '\n';
    return 0;
}
