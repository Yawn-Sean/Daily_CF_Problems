/*
显然每个 P 至多转身 1 次，因为多次转身肯定更差
考虑二分答案验证，但是以怎样的策略验证？
每个 * 应该被左右离自己最近的两个 P 之一取到，不然肯定不优
最左边那个 P，需要考虑在把左边的 * 都吃到的情况下，最多能吃到右边几个 *
枚举能吃到的最右边 * 的位置，看先左后右和先右后左这两个策略哪个能吃到，都吃不到就翡了
*/

string s;
int n;

bool check(int ans) {
    int left = 0, right = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') {
            left = i;
            break;
        }
    }
    assert(left != 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') {
            if (left < i && i - left > ans) {
                return false;
            }
            right = i + 1;
            for ( ; right <= n && s[right] != 'P'; right++) {
                if (s[right] == '*') {
                    if (left < i) {
                        int t1 = (i - left) * 2 + right - i;
                        int t2 = (right - i) * 2 + i - left;
                        if (min(t1, t2) > ans) {
                            break;
                        } 
                    } else {
                        int t1 = right - i;
                        if (t1 > ans) {
                            break;
                        }
                    }
                }
            }
            // s[right] 为到不了的 *，或者越界，或者 P
            if (right > n) {
                left = n + 1;
                break;
            }
            assert(s[right] == '*' || s[right] == 'P');
            left = right;
        }
    }
    return left > n;
}

void meibao() {
    cin >> n >> s;
    s = " " + s;
    int l = 0, r = 2 * n, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }
}
