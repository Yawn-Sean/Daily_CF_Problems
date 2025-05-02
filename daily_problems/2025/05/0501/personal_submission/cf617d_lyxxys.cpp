void solve(){
    using point = array<int,2>;

    auto chk_x = [&](point u1, point u2, point u3)->bool{
        return u1[0] == u2[0] && (u3[1] >= max(u1[1], u2[1]) || u3[1] <= min(u1[1], u2[1]));
    };
    auto chk_y = [&](point u1, point u2, point u3)->bool{
        return u1[1] == u2[1] && (u3[0] >= max(u1[0], u2[0]) || u3[0] <= min(u1[0], u2[0]));
    };
    vector<point> U(3);
    for (auto &[x, y] : U){
        cin >> x >> y;
    }

    if (U[0][0] == U[1][0] && U[1][0] == U[2][0] || U[0][1] == U[1][1] && U[1][1] == U[2][1]){
        cout << 1 << "\n";
        return;
    }

    vector <int> idx(3);
    iota(idx.begin(), idx.end(), 0);

    do {
        if (chk_x(U[idx[0]], U[idx[1]], U[idx[2]]) || chk_y(U[idx[0]], U[idx[1]], U[idx[2]])){
            cout << 2 << "\n";
            return;
        }
    } while (next_permutation(idx.begin(), idx.end()));

    cout << 3 << "\n";
}
