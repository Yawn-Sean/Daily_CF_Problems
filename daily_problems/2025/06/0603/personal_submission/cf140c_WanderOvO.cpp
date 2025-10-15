/*
如何匹配是最优的？
如果有一种半径出现了很多次，则优先每次都拿最多的那个
维护优先队列，存 (个数，半径)，每次弹出 3 个最大的，处理完插入回去
*/

int n;
map<int, int> cnt;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    priority_queue<PII> pq;
    for (auto it : cnt) {
        pq.push({it.y, it.x});
    }
    vector<vector<int>> res;
    while (pq.size() >= 3) {
        auto r1 = pq.top();
        pq.pop();
        auto r2 = pq.top();
        pq.pop();
        auto r3 = pq.top();
        pq.pop();
        r1.x--;
        r2.x--;
        r3.x--;
        vector<int> choice;
        choice.push_back(r1.y);
        choice.push_back(r2.y);
        choice.push_back(r3.y);
        sort(choice.begin(), choice.end());
        reverse(choice.begin(), choice.end());
        res.push_back(choice);
        if (r1.x > 0) {
            pq.push(r1);
        }
        if (r2.x > 0) {
            pq.push(r2);
        }
        if (r3.x > 0) {
            pq.push(r3);
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        for (auto r : res[i]) {
            cout << r << " ";
        }
        cout << "\n";
    }
}
