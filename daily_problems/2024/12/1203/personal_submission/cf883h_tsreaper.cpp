#include <bits/stdc++.h>
#define MAXN ((int) 4e5)
#define SIGMA 128
using namespace std;

int n;
char s[MAXN + 5];

int odd, cnt[SIGMA];

vector<string> check(int sz) {
    int len = n / sz;
    vector<string> ret;
    for (int i = 0; i < sz; i++) {
        string s;
        s.resize(len);
        ret.push_back(s);
    }

    if (len & 1) {
        if (odd > sz) return {};
        int rem = sz - odd;
        if (rem & 1) return {};

        int j = 0;
        for (int i = 0; i < SIGMA; i++) if (cnt[i] & 1) {
            ret[j++][len / 2] = i;
            cnt[i]--;
        }
        for (int i = 0; j < sz; j += 2) {
            while (cnt[i] == 0) i++;
            ret[j][len / 2] = ret[j + 1][len / 2] = i;
            cnt[i] -= 2;
        }
    } else {
        if (odd > 0) return {};
    }

    for (int j = 0, i = 0; j < sz; j++) {
        for (int l = 0, r = len - 1; l < r; l++, r--) {
            while (cnt[i] == 0) i++;
            ret[j][l] = ret[j][r] = i;
            cnt[i] -= 2;
        }
    }
    return ret;
}

int main() {
    scanf("%d%s", &n, s + 1);

    for (int i = 1; i <= n; i++) cnt[s[i]]++;
    for (int i = 0; i < SIGMA; i++) if (cnt[i] & 1) odd++;

    for (int i = 1; i <= n; i++) if (n % i == 0) {
        vector<string> vec = check(i);
        if (vec.size() == i) {
            printf("%d\n", i);
            for (int j = 0; j < i; j++) printf("%s%c", vec[j].c_str(), "\n "[j + 1 < i]);
            return 0;
        }
    }
    return 0;
}
