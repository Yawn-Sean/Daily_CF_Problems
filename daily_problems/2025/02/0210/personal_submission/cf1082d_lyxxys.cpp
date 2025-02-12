void solve(){
    int n;
    cin >> n;
    vector <int> A(n), vt1, vt2;
    vector<array<int,2>> ans;
    auto push = [&](int x, int y)->void{
        ans.push_back({x+1,y+1});
    };

    int all = 0;
    for (int i = 0; i < n; ++ i){
        int &x = A[i];
        cin >> x;
        if (x == 1) vt1.push_back(i);
        else {
            vt2.push_back(i);
            all += x;
        }
    }

    int sm = vt2.size() > 1 ? all-2*(int)vt2.size()+2 : all;
    if (vt1.size() > sm){
        cout << "NO\n";
        return;
    }

    sort(vt2.begin(), vt2.end(), [&](auto &u, auto &v){
        return A[u] < A[v];
    });
    if (vt2.size() > 2){  // 保证两边度数尽可能大
        swap(vt2[0], vt2[vt2.size()-2]);
    }

    for (int i = 1; i < vt2.size(); ++ i){
        push(vt2[i-1], vt2[i]);
    }
    if (vt2.size() > 1){
        for (int i = 0; i < vt2.size(); ++ i){
            int x = vt2[i];
            if (i == 0 || i == vt2.size()-1) A[x] -= 1;
            else A[x] -= 2;
        }
    }

    int dia = vt2.size();
    if (vt1.size() && A[vt2[0]]){
        push(vt2[0], vt1.back());
        vt1.pop_back(), dia += 1, A[vt2[0]] -= 1;
    }
    if (vt1.size() && A[vt2.back()]){
        push(vt2.back(), vt1.back());
        vt1.pop_back(), dia += 1, A[vt2.back()] -= 1;
    }
    for (auto &id : vt2){
        while (A[id] > 0 && !vt1.empty()){
            push(id, vt1.back());
            vt1.pop_back(), A[id] -= 1;
        }
        if (vt1.empty()) break;
    }

    cout << "YES" << " " << dia-1 << "\n";
    cout << ans.size() << "\n";
    for (auto &[u,v] : ans){
        cout << u << " " << v << "\n";
    }
}

