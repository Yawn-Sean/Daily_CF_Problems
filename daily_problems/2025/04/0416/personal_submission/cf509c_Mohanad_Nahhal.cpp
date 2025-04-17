/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string last;
    for (int i = 0; i < n; i ++) {
        int sum, summ = 0;
        cin >> sum;

        string num;
        for (int j = 0; j < last.size(); j ++) {
            for (int add = 1; add <= 9; add ++) {
                if (last[j] + add > '9') break;
                if (sum - (summ + last[j] - '0' + add) <= (last.size() - j - 1) * 9 && sum - (summ + last[j] - '0' + add) >= 0) {
                    string numm = last.substr(0, j + 1), bb;
                    numm.back() += add;
                    int rest = sum - (summ + last[j] - '0' + add);
                    while (rest) {
                        bb.push_back('0' + min(rest, 9));
                        rest -= min(rest, 9);
                    }
                    reverse(bb.begin(), bb.end());
                    while (numm.size() + bb.size() != last.size()) numm.push_back('0');
                    numm += bb;
                    if (num.size() == 0) num = numm;
                    num = min(num, numm);
                }
            }
            summ += last[j] - '0';
        }

        if (num.size() == 0) {
            int len = last.size() + 1;
            while (true) {
                if (num.size()) break;
                for (int first = 1; first <= 9; first ++) {
                    string numm;
                    numm.push_back(first + '0');
                    int rest = sum - first;
                    if ((len - 1) * 9 >= rest && rest >= 0) {
                        string bb;
                        while (rest) {
                            bb.push_back('0' + min(rest, 9));
                            rest -= min(rest, 9);
                        }
                        reverse(bb.begin(), bb.end());
                        while (numm.size() + bb.size() != len) numm.push_back('0');
                        numm += bb;
                        if (num.size() == 0) num = numm;
                        num = min(num, numm);
                    }
                }
                len ++;
            }
        }
        cout << num << endl;
        last = num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
