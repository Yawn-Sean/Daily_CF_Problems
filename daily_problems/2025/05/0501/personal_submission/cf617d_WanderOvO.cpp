/*
题目保证了没有重合的点
三个点横坐标或者纵坐标都相等，则只需要一条线
三个点中有两个点的横坐标/纵坐标相等：
- 如果第 3 个点的另一个坐标不在二者之间，就可以 2 条线
*/

void meibao() {
    int x[4], y[4];
    for (int i = 1; i <= 3; i++) {
        cin >> x[i] >> y[i];
    }
    if ( (x[1] == x[2] && x[2] == x[3]) || (y[1] == y[2] && y[2] == y[3]) ) {
        cout << "1\n";
    } else {
        bool ok = false;
        for (int i = 1; i <= 3; i++) {
            for (int j = i + 1; j <= 3; j++) {
                int k = 6 - i - j;
                if (x[i] == x[j]) {
                    if (y[k] <= min(y[i], y[j]) || y[k] >= max(y[i], y[j])) {
                        ok = true;
                    }    
                } 
                if (y[i] == y[j]) {
                    if (x[k] <= min(x[i], x[j]) || x[k] >= max(x[i], x[j])) {
                        ok = true;
                    }
                }
            }
        }
        if (ok) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
}   
