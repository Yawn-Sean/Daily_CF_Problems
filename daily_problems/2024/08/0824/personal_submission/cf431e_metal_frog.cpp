const double eps = 1e-8;

int sgn(double x) {
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> tube(n);
    vector<ll> values;
    for (int i = 0; i < n; i++) {
        cin >> tube[i];
        values.emplace_back(tube[i]);
    }
    vector<vector<ll>> query(q, vector<ll>(3));
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        query[i][0] = tp;
        if (tp == 1) {
            cin >> query[i][1] >> query[i][2];
            query[i][1]--;
            values.emplace_back(query[i][2]);
        } else {
            cin >> query[i][1];
        }
    }
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    auto getId = [&](const ll& x) -> int {
        return lower_bound(all(values), x) - values.begin();
    };
    int len = sz(values);
    FT cntTree(len + 1), sumTree(len + 1);
    for (int i = 0; i < n; i++) {
        int id = getId(tube[i]);;
        sumTree.update(id, tube[i]);
        cntTree.update(id, 1);
    }
    for (int t = 0; t < q; t++) {
        int tp = query[t][0];
        if (tp == 1) {
            int tubeID = query[t][1];
            ll newVal = query[t][2];
            int idOfNewVal = getId(newVal), idOfOldVal = getId(tube[tubeID]);
            sumTree.update(idOfOldVal, -tube[tubeID]);
            sumTree.update(idOfNewVal, newVal);
            cntTree.update(idOfNewVal, 1);
            cntTree.update(idOfOldVal, -1);
            tube[tubeID] = newVal;
        } else {
            double water = query[t][1];
            double lo = 0.0, hi = 1e9 + water + 1.0;
            for (int search = 0; search < 100; search++) {
                double mid = lo + (hi - lo) / 2.0;
                ll roundNum = floor(mid);
                int ub = upper_bound(all(values), roundNum) - values.begin();
                double cnt = cntTree.query(ub);
                double sum = sumTree.query(ub);
                double val = cnt * mid - sum - water; 
                //cout << mid << " " << cnt << " " << roundNum << endl;
                if (sgn(val) >= 0) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            cout << setprecision(6) << lo << "\n";
        }
    }
}
