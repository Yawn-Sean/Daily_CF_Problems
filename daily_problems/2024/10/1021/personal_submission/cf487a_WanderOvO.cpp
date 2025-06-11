int hp[3], atk[3], def[3], h, a, d;

void meibao() {
    cin >> hp[1] >> atk[1] >> def[1];
    cin >> hp[2] >> atk[2] >> def[2];
    cin >> h >> a >> d;
    int min_cost = N;
    for (int j = 0; j <= 200; j++) {
        for (int k = 0; k <= 200; k++) {
            int cost = j * a + k * d;
            int y_hp = 0, y_atk = atk[1] + j, y_def = def[1] + k;
            int m_hp = hp[2], m_atk = atk[2], m_def = def[2];
            if (y_atk <= m_def) {
                continue;
            }
            while (m_hp > 0) {
                y_hp -= max(0, m_atk - y_def);
                m_hp -= max(0, y_atk - m_def);
            }
            int i = 0;
            if (y_hp + hp[1] <= 0) {
                i = abs(y_hp + hp[1]) + 1;
            }
            cost += i * h;
            min_cost = min(min_cost, cost);
        }
    }
    cout << min_cost << "\n";
}    
