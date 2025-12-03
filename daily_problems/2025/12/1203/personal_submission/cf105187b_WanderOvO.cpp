int n;
int p[N];
int match_opp[N];
PII matches[N];

int get_cost(int u, int v, int k) {
    int c1 = (p[u] + 3 > k) + (p[v] > k);
    int c2 = (p[u] > k) + (p[v] + 3 > k);
    int c3 = (p[u] + 1 > k) + (p[v] + 1 > k);
    return min({c1, c2, c3});
}

void solve() {
    cin >> n;
    int num_teams = 2 * n;
    for (int i = 0; i < num_teams; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        matches[i] = {u, v};
        match_opp[u] = v;
        match_opp[v] = u;
    }

    vector<int> vals;
    vals.push_back(-1);

    for (int i = 0; i < num_teams; i++) {
        vals.push_back(p[i] + 3);
        vals.push_back(p[i]);
        vals.push_back(p[i] + 1);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int sz = vals.size();
    vector<int> D(sz + 1, 0);

    D[0] = 2 * n;

    for (int i = 0; i < n; i++) {
        int u = matches[i].first;
        int v = matches[i].second;

        vector<int> crits;
        crits.push_back(p[u]);
        crits.push_back(p[u] + 1);
        crits.push_back(p[u] + 3);
        crits.push_back(p[v]);
        crits.push_back(p[v] + 1);
        crits.push_back(p[v] + 3);
        
        sort(crits.begin(), crits.end());
        crits.erase(unique(crits.begin(), crits.end()), crits.end());

        int prev_c = 2; 
        
        for (int val : crits) {
            int idx = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
            int cur_c = get_cost(u, v, val);
            int delta = cur_c - prev_c;
            D[idx] += delta;
            prev_c = cur_c;
        }
    }

    for (int i = 1; i < sz; i++) {
        D[i] += D[i - 1];
    }

    for (int i = 0; i < num_teams; i++) {
        int K = p[i] + 3;
        int idx = lower_bound(vals.begin(), vals.end(), K) - vals.begin();
        int global_score = D[idx];

        int u = i;
        int v = match_opp[i];
        
        int generic = get_cost(u, v, K);
        int specific = (p[v] > K); 

        cout << global_score - generic + specific + 1 << " ";
    }
    cout << endl;
}
