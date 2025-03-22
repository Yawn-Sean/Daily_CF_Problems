#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, x, mod3, sum;
int cnt[10];
int minimum[3][2];

int main() {
    scanf("%d", &n);
    minimum[1][0] = minimum[1][1] = minimum[2][0] = minimum[2][1] = 10;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        ++cnt[x];
        if (x < minimum[x % 3][0]) {
            minimum[x % 3][1] = minimum[x % 3][0];
            minimum[x % 3][0] = x;
        }
        else if (x < minimum[x % 3][1]) {
            minimum[x % 3][1] = x;
        }
        mod3 = (mod3 + x) % 3;
    }
    if (cnt[0] == 0) {
        printf("-1\n");
        return 0;
    }
    if (mod3 != 0) {
        if (minimum[mod3][0] < 10) {
            --cnt[minimum[mod3][0]];
        }
        else if (minimum[3 - mod3][1] < 10) {
            --cnt[minimum[3 - mod3][0]];
            --cnt[minimum[3 - mod3][1]];
        }
        else {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 1; i <= 9; ++i) sum += cnt[i];
    if (sum == 0) cnt[0] = 1;
    for (int i = 9; i >= 0; --i) {
        for (int j = 1; j <= cnt[i]; ++j) printf("%d", i);
    }
    printf("\n");
    return 0;
}