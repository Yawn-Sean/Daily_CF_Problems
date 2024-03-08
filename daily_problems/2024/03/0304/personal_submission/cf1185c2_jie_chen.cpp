/***************************************************************************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 03.03.2024 20:35:41
****************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#ifdef BROKEN_CODE
#include <bits/debug.h>
#else
#define dbg(...) 10082002
#define dbp(...) "Gimme Internship"
#endif

using i64 = long long;

constexpr int LIM = 101;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    vector<int> cnt(LIM);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x = t[i];
        int rem = 0;
        if (sum + x > m) {
            int suf = 0;
            for (int j = LIM - 1; j > 0; j--) {
                int tot = j * cnt[j];
                if (sum + x - (suf + tot) <= m) {
                    rem += (sum + x - suf - m + j - 1) / j;
                    break;
                } else {
                    suf += tot;
                    rem += cnt[j];
                }
            }
        }
        sum += x;
        cnt[x]++;
        printf("%d%c", rem, " \n"[i == n - 1]);
    }
}

// ~ Just Jie
