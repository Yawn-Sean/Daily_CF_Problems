/*
一定是先走若干的完整的，再走一个前缀，所以先算一下走一套完整的偏移量是多少
然后枚举前缀，看剩下要走的能不能通过走若干个完整的走出来
*/

string s;
LL a, b;

void meibao() {
    cin >> a >> b >> s;
    LL delta_x = 0, delta_y = 0;
    if (a == 0 && b == 0) {
        cout << "Yes\n";
        return;
    }

    for (auto ch : s) {
        if (ch == 'U') {
            delta_y++;
        } else if (ch == 'D') {
            delta_y--;
        } else if (ch == 'L') {
            delta_x--;
        } else {
            delta_x++;
        }
    }

    LL cur_x = 0, cur_y = 0;
    bool ok = false;
    for (auto ch : s) {
        if (ch == 'U') {
            cur_y++;
        } else if (ch == 'D') {
            cur_y--;
        } else if (ch == 'L') {
            cur_x--;
        } else {
            cur_x++;
        }
        LL dx = a - cur_x, dy = b - cur_y;
        // k * delta_x = dx
        // k * delta_y = dy
        if (dx == 0 && dy == 0) {
            ok = true;
            break;
        }
        if (delta_x && delta_y) {
            if (dx % delta_x == 0 && dy % delta_y == 0 && dx / delta_x == dy / delta_y && dx / delta_x >= 0) {
                ok = true;
                break;
            } 
        } else if (delta_x) {
            if (dx % delta_x == 0 && dy == 0 && dx / delta_x >= 0) {
                ok = true;
                break;
            }
        } else if (delta_y) {
            if (dy % delta_y == 0 && dx == 0 && dy / delta_y >= 0) {
                ok = true;
                break;
            }
        } else {
            if (dx == 0 && dy == 0) {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}
