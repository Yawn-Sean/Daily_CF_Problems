/*
n 个点，其中有 k 个点是只连 1 条边的，最小化树的直径
似乎固定 1 号点，假如有 k 个只连 1 条边的，就尽量贪心平均分 k 个叉即可
不节外生枝肯定不差于节外生枝
*/

int T;

void solve1() {
    int n, k;
    cin >> n >> k;
    int avg = (n - 1) / k;
    int r = (n - 1) % k;
    if (r >= 2) {
        r = 2;
    } 
    cout << 2 * avg + r << "\n";
    for (int i = 2; i <= k + 1; i++) {
        cout << "1 " << i << "\n";
    }
    for (int i = k + 2; i <= n; i++) {
        cout << i - k << " " << i << "\n";
    }
}   
