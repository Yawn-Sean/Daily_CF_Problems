void dijkstra(int bg) {
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> heap;
    heap.push(make_tuple(0, bg, -1));
    dist[bg] = 0;
    int cnt = 0;
    vector<int> ans;
    while (!heap.empty() && cnt < k) {
        Tuple t = heap.top();
        heap.pop();
        if (st[get<1>(t)]) continue;
        st[get<1>(t)] = true;
        if (get<0>(t) != 0) {
            cnt++;
            ans.push_back(get<2>(t) / 2);
        }
        for (int i = h[get<1>(t)]; i != -1; i = ne[i]) {
            int j = e[i], z = w[i];
            if (dist[j] > get<0>(t) + z) {
                dist[j] = get<0>(t) + z;
                heap.push(make_tuple(dist[j], j, i));
            }
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x + 1 << " ";
    }
}