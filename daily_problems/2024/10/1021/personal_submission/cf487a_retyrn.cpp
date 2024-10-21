int h, a, d;

struct S {
    int hp;
    int at;
    int de;
};

void solve() {
    S yang, mon;
    cin >> yang.hp >> yang.at >> yang.de;
    cin >> mon.hp >> mon.at >> mon.de;
    cin >> h >> a >> d;
    
    int res = inf;

    for (int atk = max(yang.at, mon.de + 1); atk <= max(mon.hp + mon.de, yang.at); atk ++) {
        for (int def = yang.de; def <= max(yang.de, mon.at); def ++) {
            // 多久杀死怪物
            int t = (mon.hp - 1) / (atk - mon.de) + 1;
            int need = max(mon.at - def, 0) * t + 1;
            int cost = max(0, need - yang.hp) * h + (atk - yang.at) * a + (def - yang.de) * d;
            chmin(res, cost);
        }
    }
    
    cout << res << endl;
}