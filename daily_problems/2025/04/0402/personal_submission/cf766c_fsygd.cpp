#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char s[1010];
int f[1010][3];
int limit[26];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 0; i < 26; ++i) scanf("%d", &limit[i]);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) f[i][2] = n;
    for (int i = 0; i < n; ++i) {
        int min_limit = 1000;
        for (int j = i + 1; j <= n; ++j) {
            min_limit = min(min_limit, limit[s[j] - 'a']);
            if (j - i > min_limit) break;
            f[j][0] = (f[j][0] + f[i][0]) % 1000000007;
            f[j][1] = max(f[j][1], max(f[i][1], j - i));
            f[j][2] = min(f[j][2], f[i][2] + 1);
        }
    }
    printf("%d\n%d\n%d\n", f[n][0], f[n][1], f[n][2]);
    return 0;
}