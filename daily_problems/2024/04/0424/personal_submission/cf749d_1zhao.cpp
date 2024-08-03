void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    vector<int> S(n);
    unordered_set<int> us;
    unordered_map<int, vector<int>> um;
    for(int i=n-1; i>=0; i--) {
        us.insert(a[i].first);
        S[i] = us.size();
        if(!um.count(a[i].first)) {
            um[a[i].first] = {i};
        } else {
            um[a[i].first].push_back(i);
        }
    }

    int m;
    cin >> m;
    while(m --) {
        int k;
        cin >> k;
        vector<int> b(k);        
        unordered_set<int> bs;
        for(int i=0; i<k; i++) {
            cin >> b[i];
            bs.insert(b[i]);
        }
        
        int l=0, r=n-1;
        while(l < r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int i:b) {
                if(um.count(i)) {
                    cnt += um[i][0] >= mid;
                }
            }
            cnt = S[mid] - cnt;
            if(cnt == 1) {
                if(bs.count(a[mid].first)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else if(cnt > 1) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l == 0 && bs.count(a[0].first)) {
            cout << "0 0" << endl;
            continue;
        }

        int idx = a[l].first;
        int l2 = 0, r2 = um[idx].size()-1;
        while(l2 < r2) {
            int mid = (l2 + r2 + 1) / 2;
            int t = um[idx][mid];
            
            int cnt = 0;
            for(int i:b) {
                if(um.count(i)) {
                    cnt += um[i][0] >= t;
                }
            }
            cnt = S[t] - cnt;

            if(cnt > 1) {
                r2 = mid - 1;
            } else {
                l2 = mid;
            }
        }
        int res = um[idx][l2];
        cout << idx << ' ' << a[res].second << endl; 

    }

}    
