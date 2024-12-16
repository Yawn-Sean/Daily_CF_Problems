#include <bits/stdc++.h>
using namespace std;

string I() {
    string s;
    getline(cin, s);
    return s;
}

string main_fun() {
    string s = I();
    int ln = s.size();

    if (ln % 2 == 1) {
        int n = ln + 1;
        int half = n / 2;
        string res = "";
        for (int i = 0; i < half; ++i) {
            res += "4";
        }
        for (int i = 0; i < half; ++i) {
            res += "7";
        }
        return res;
    }

    int half = ln / 2;
    if (s > string(half, '7') + string(half, '4')) {
        string res = "";
        for (int i = 0; i < half + 1; ++i) {
            res += "4";
        }
        for (int i = 0; i < half + 1; ++i) {
            res += "7";
        }
        return res;
    }

    string ans(ln, ' ');
    int cnt4 = half, cnt7 = half;
    bool found = false;
    function<void(int, int, bool)> dfs = [&](int i, int rest4, bool isLimited) {
        if (i == ln || found) {
            found = true;
            return;
        }
        int rest7 = half - (i - half + rest4);
        if (!isLimited) {
            if (rest4) {
                ans[i] = '4';
                dfs(i + 1, rest4 - 1, false);
            }
            else {
                ans[i] = '7';
                dfs(i + 1, 0, false);
            }
        }
        else {
            int x = s[i] - '0';
            if (rest4 && 4 >= x) {
                ans[i] = '4';
                dfs(i + 1, rest4 - 1, x == 4);
            }
            if (found) return;
            if (rest7 && 7 >= x) {
                ans[i] = '7';
                dfs(i + 1, rest4, x == 7);
            }
        }
    };
    dfs(0, cnt4, true);
    return ans;
}

int main() {
    int tt = 1;
    for (int ii = 0; ii < tt; ++ii) {
        cout << main_fun() << endl;
    }
    return 0;
}
