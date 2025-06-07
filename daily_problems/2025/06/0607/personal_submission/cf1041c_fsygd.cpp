#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, d, ans, head, tail;
int a[200010], idx[200010], last[200010], nxt[200010], day[200010];

bool cmp(int X, int Y) {
    return a[X] < a[Y];
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        idx[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    ans = head = tail = 1;
    last[1] = a[idx[1]];
    day[idx[1]] = 1;

    for (int i = 2; i <= n; ++i) {
        if (a[idx[i]] < last[head] + d + 1) {
            last[++ans] = a[idx[i]];
            day[idx[i]] = ans;
            nxt[tail] = ans;
            tail = ans;
        } else {
            last[head] = a[idx[i]];
            day[idx[i]] = head;
            if (head != tail) {
                nxt[tail] = head;
                int tmp = nxt[head];
                nxt[head] = 0;
                tail = head;
                head = tmp;
            }
        }
    }
    
    printf("%d\n", ans);
    for (int i = 1; i < n; ++i) printf("%d ", day[i]);
    printf("%d\n", day[n]);
    return 0;
}