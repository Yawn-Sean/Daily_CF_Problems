void solve(){
    int n;
    cin >> n;
    vector <string> names(n);
    vector <int> idx(n), A(n);
    for (int i = 0; i < n; ++ i){
        cin >> names[i] >> A[i];
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return A[u] < A[v];
    });

    vector <int> w(n), curs;

    for (int i = 0; i < n; ++ i){
        int id = idx[i], need = A[id], cur;
        if (need > i){
            cout << -1 << "\n";
            return;
        }

        assert(curs.size() == i);

        int j = i;
        while (need > 0){
            -- need;
            j -= 1;
        }
        if (j == i){
            if (curs.empty()){
                w[id] = (int)1e5;
            } else {
                w[id] = w[curs.back()] + 1;
            }
            curs.push_back(id);
        } else {
            w[id] = w[curs[j]]-1;
            curs.insert(curs.begin()+j, id);
            j -= 1;
            if (j >= 0 && w[curs[j]] == w[id]){
                while (j >= 0){
                    w[curs[j]] -= 1;
                    j -= 1;
                }
            }
        }
    }

    for (auto &id : idx){
        cout << names[id] << " " << w[id] << "\n";
    }
}
