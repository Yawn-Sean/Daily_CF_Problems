/*
数组 a 由三段组成：包含 a[1] 的最长的严格递增段，中间段，包含 a[n] 的最长严格递减段
我们只会用到第一段和第三段
对于 Alice，假如他取完之后，无论如何都还有偶数个可以取，那他就赢了
对于 Bob 也是一样的，也是偶数个就可以赢
假如两边都是偶数，Bob 只要跟着 Alice 拿就能赢
假如一奇一偶，则 Alice 只要拿奇数那边，Bob 就必输了
假如两边都是奇数，则让 Alice 拿更大的那边，然后 Bob 只能跟着拿，Bob 必输
*/

int T;
int n, a[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1;
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] > a[i - 1]) {
            l = i;
        } else {
            break;
        }
    }
    int r = n;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > a[i + 1]) {
            r = i;
        } else {
            break;
        }
    }
    int len1 = l, len3 = n - r + 1;
    if (len1 % 2 == 0 && len3 % 2 == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}   
