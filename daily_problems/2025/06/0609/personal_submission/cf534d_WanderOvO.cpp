/*
0 1 2 起手
后边可以选 3
找不到就 -3 再找
顺序好像无所谓
*/

vector<vector<int>> pos(N);
int n, a[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int cur = 0;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        while (cur >= 0 && pos[cur].size() == 0) {
            cur -= 3;
        }
        if (cur < 0) {
            cout << "Impossible\n";
            return;
        }
        res.push_back(pos[cur].back());
        pos[cur].pop_back();
        cur++;
    }
    cout << "Possible\n";
    for (auto id : res) {
        cout << id << " ";
    }
}
