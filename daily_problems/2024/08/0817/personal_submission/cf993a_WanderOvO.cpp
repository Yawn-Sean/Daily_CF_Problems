bool overlap(vector<int> square1, vector<int> square2) {
    int up = -110, down = 110, left = 110, right = -110;
    for (int i = 0; i < 8; i += 2) {
        left = min(left, square1[i]);
        right = max(right, square1[i]);
    }
    for (int i = 1; i < 8; i += 2) {
        up = max(up, square1[i]);
        down = min(down, square1[i]);
    }
    for (int i = 0; i < 8; i += 2) {
        int x = square2[i], y = square2[i + 1];
        if (x >= left && x <= right && y >= down && y <= up) {
            return true;
        }
    }
    int midx = square2[0] + square2[4], midy = square2[1] + square2[5];
    return midx >= left * 2 
        && midx <= right * 2 
        && midy >= down * 2 
        && midy <= up * 2;
}

void solve1() {
    vector<int> square1(8), square2(8);
    for (int i = 0; i < 8; i++) {
        cin >> square1[i];
    }
    for (int i = 0; i < 8; i++) {
        cin >> square2[i];
    }
    if (!overlap(square1, square2)) {
        for (int i = 0; i < 8; i += 2) {
            square1[i] += square1[i + 1];
            square1[i + 1] = square1[i] - 2 * square1[i + 1];
            square2[i] += square2[i + 1];
            square2[i + 1] = square2[i] - 2 * square2[i + 1];
        }
        if (!overlap(square2, square1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        cout << "YES\n";
    }
}                                                                                                                  
