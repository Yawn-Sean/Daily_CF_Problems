#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T, one, two, three, four;

int get_ans(int one, int two, int three) {
    int ans = one / 2 + two / 2 + three / 2;
    if (one >= 1 && two >= 1 && three >= 1) ans = max(ans, (one - 1) / 2 + (two - 1) / 2 + (three - 1) / 2 + 1);
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &one, &two, &three, &four);
        int value = 0;
        if (one & 1) value ^= 1;
        if (two & 1) value ^= 2;
        if (three & 1) value ^= 3;

        int ans = 0;
        if (value == 0)
            ans = get_ans(one, two, three);
        else if (value == 1) {
            if (one >= 1) ans = max(ans, get_ans(one - 1, two, three));
            if (two >= 1 && three >= 1) ans = max(ans, get_ans(one, two - 1, three - 1));
        }
        else if (value == 2) {
            if (two >= 1) ans = max(ans, get_ans(one, two - 1, three));
            if (one >= 1 && three >= 1) ans = max(ans, get_ans(one - 1, two, three - 1));
        }
        else {
            if (three >= 1) ans = max(ans, get_ans(one, two, three - 1));
            if (one >= 1 && two >= 1) ans = max(ans, get_ans(one - 1, two - 1, three));
        }
        printf("%d\n", ans + four / 2);
    }
    return 0;
}