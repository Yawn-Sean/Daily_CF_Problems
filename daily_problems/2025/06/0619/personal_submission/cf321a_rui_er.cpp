int tx, ty, n;
string s;
map<char, tuple<int, int>> mp{
    {'U', {0, +1}}, 
    {'D', {0, -1}}, 
    {'L', {-1, 0}}, 
    {'R', {+1, 0}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tx >> ty >> s;
    n = s.size();
    if(!tx && !ty) {
        cout << "Yes" << endl;
        return 0;
    }
    int mx = 0, my = 0;
    for(char c: s) {
        auto [dx, dy] = mp[c];
        mx += dx;
        my += dy;
        if(mx == tx && my == ty) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(!mx && !my) {
        int rx = 0, ry = 0;
        for(char c: s) {
            auto [dx, dy] = mp[c];
            rx += dx;
            ry += dy;
            if(tx == rx && ty == ry) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    if(!mx) {
        int rx = 0, ry = 0;
        for(char c: s) {
            auto [dx, dy] = mp[c];
            rx += dx;
            ry += dy;
            if(tx == rx && (ty - ry) % my == 0 && (ty - ry) / my > 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    if(!my) {
        int rx = 0, ry = 0;
        for(char c: s) {
            auto [dx, dy] = mp[c];
            rx += dx;
            ry += dy;
            if(ty == ry && (tx - rx) % mx == 0 && (tx - rx) / mx > 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    int rx = 0, ry = 0;
    for(char c: s) {
        auto [dx, dy] = mp[c];
        rx += dx;
        ry += dy;
        if((tx - rx) % mx == 0 && (tx - rx) / mx > 0 && (ty - ry) % my == 0 && (ty - ry) / my > 0 && (tx - rx) / mx == (ty - ry) / my) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
