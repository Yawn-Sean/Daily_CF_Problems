const int N = 2e5 + 5;
int n, k, a[N];
vector<int> vec;
priority_queue<int, vector<int>, greater<int>> heap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    int flg = 0, lst = 1, id = 0, ans = 0;
    rep(i, 1, n) {
        if(a[i] < 0) {
            --k;
            id = i;
            if(!flg) {
                if(i - lst > 0 && lst != 1) heap.push(i - lst);
                flg = 1;
                ++ans;
            }
        }
        else if(flg) {
            flg = 0;
            lst = i;
            ++ans;
        }
    }
    if(k < 0) cout << -1 << endl;
    else {
        while(!heap.empty()) {
            if(k - heap.top() >= 0) {
                k -= heap.top();
                heap.pop();
                ans -= 2;
            }
            else break;
        }
        if(a[n] >= 0 && id > 0 && n - id > 0 && k - (n - id) >= 0) --ans;
        cout << ans << endl;
    }
    return 0;
}
