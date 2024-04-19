// https://codeforces.com/contest/1310/submission/257241808
void solve()
{   int n;
    cin >> n;
    priority_queue<PII> pq;
    vector<PII> num_cost(n);
    int first, second;
    for (int i = 0; i < n; i++){
        cin >> first;
        num_cost[i].first = first;
    }
    for (int i = 0; i < n; i++){
        cin >> second;
        num_cost[i].second = second;
    }
    sort(num_cost.begin(), num_cost.end());
    int now = 0;
    int idx = 0;
    LL ret = 0;
    LL tot = 0;
    while (idx < n || !pq.empty()){
        now ++;
        if (pq.empty()){
            now = num_cost[idx].first;
        } 
        while (idx < n && num_cost[idx].first == now){
            pq.push({num_cost[idx].second, num_cost[idx].first});
            tot += num_cost[idx].second;
            idx++;
        }
        tot -= pq.top().first;pq.pop();
        ret += tot;
    }

    cout << ret << '\n';
}
