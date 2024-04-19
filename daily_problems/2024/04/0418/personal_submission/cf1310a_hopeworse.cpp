void solve() {
    int n;
    cin >> n;
    int cost = 0;
    priority_queue<int> pq;
    pqinit<pair<int, int> > lst;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int now = 0;
    int i = 0;
    while (i < n) {
        now = arr[i].first;
        while (i < n && arr[i].first <= now) {
            lst.push({arr[i].second, arr[i].first});
            i++;
        }
        int next = (i == n) ? inf : arr[i].first - 1;
        while (pq.empty() || pq.top() < next) {
            if (lst.empty()) {
                break;
            }
            auto [a, b] = lst.top();
            lst.pop();
            if (!pq.empty() && pq.top() >= b) {
                debug("turn", b, pq.top() + 1, a * (pq.top() + 1 - b));
                cost += a * (pq.top() + 1 - b);
                pq.emplace(pq.top() + 1);
            } else {
                pq.emplace(now);
            }
        }

    }
    while (!lst.empty()) {
        auto [a, b] = lst.top();
        lst.pop();
        if (pq.top() >= b) {
            debug("turn", b, pq.top() + 1, a * (pq.top() + 1 - b));
            cost += a * (pq.top() + 1 - b);
            pq.emplace(pq.top() + 1);
        } else {
            pq.emplace(b);
        }
    }

    cout << cost << endl;
}
