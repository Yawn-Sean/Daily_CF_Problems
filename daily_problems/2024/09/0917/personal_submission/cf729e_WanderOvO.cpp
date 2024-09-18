/*
假如有个人的上司有 cnt 个，则肯定有至少一个人的上司有 cnt - 1 个
根的上司个数是 0 个，也只有根的可以是 0，可以先判断根的对不对
对于剩下的，排个序之后再检查一下
首先看第一个是不是 1，不是则肯定是错的
如果其他的排完序是 1 1 3 3 3 3 3 3 3，则显然是把第二个 1 改成 2，或者把某个 3 改成 2 代价最小
似乎无脑把号称自己上司个数最多的人给改了，用于补齐前面不连续的地方，代价最小
*/

int T;
int n, s, a[N];

void solve1() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    if (a[s] != 0) {
        res++;
    }
    vector<int> others;
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            if (a[i] == 0) {
                a[i] = n;
            }
            others.pb(a[i]);
        }
    }
    sort(others.begin(), others.end());
    int ne = 1, l = 0, r = others.size() - 1;
    while (l < r) {
        if (others[l] > ne) {
            res++;
            others[r] = ne;
            r--;
            ne++;
        } else {
            if (others[l] == ne) {
                ne++;
            }
            l++;
        }
    }
    sort(others.begin(), others.end());
    if (others.size() == 1 && others[0] != 1) {
        res++;
    }
    for (int i = 1; i < others.size(); i++) {
        if (others[i] > others[i - 1] + 1) {
            res++;
        }
    }
    cout << res << "\n";
}               
