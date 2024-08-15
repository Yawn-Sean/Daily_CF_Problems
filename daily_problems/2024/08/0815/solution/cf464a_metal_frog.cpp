#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 1005;
char S[N];

void solve() {
    int n, lim;
    scanf("%d %d", &n, &lim);
    scanf("%s", S);
    bool find = false;
    for (int i = n - 1; i >= 0; i--) {
        for (char c = S[i] + 1; c < 'a' + lim; c++) {
            bool flag = true;
            if (i - 1 >= 0 && S[i - 1] == c) flag = false;
            if (i - 2 >= 0 && S[i - 2] == c) flag = false;
            if (flag) {
                S[i] = c;
                for (int j = i + 1; j < n; j++) {
                    for (char cc = 'a'; cc < 'a' + lim; cc++) {
                        bool flag2 = true;
                        if (j - 1 >= 0 && S[j - 1] == cc) flag2 = false;
                        if (j - 2 >= 0 && S[j - 2] == cc) flag2 = false;
                        if (flag2) {
                            S[j] = cc;
                            break;
                        }
                    }
                }
                find = true;
                goto finish;
            }
        }
    }
finish:
    if (!find) {
        printf("NO\n");
        return;
    }
    printf("%s\n", S);
}
 
int main() {
    solve();
}
