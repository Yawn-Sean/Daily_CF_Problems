#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int hp_y, atk_y, def_y;
	int hp_m, atk_m, def_m;
	cin >> hp_y >> atk_y >> def_y;
	cin >> hp_m >> atk_m >> def_m;
	
	int h, a, d;
	cin >> h >> a >> d;
	
	int ans = 1e9;
	for (int def = 0; def <= max(0, atk_m - def_y); def++) {
		int cost_d = def * d;
		int cost_a = 0, cost_h = 0;
		
		int m_damage = max(0, atk_m - (def_y + def));
		// cout << m_damage << '\n';
		
		if (m_damage > 0) {
			// hp_m 不会很大 100
			int y_damage = atk_y - def_m;
			if (y_damage <= 0) {
				cost_a += (-y_damage + 1) * a;
				y_damage = 1;
			}
			
			// atk: 去除怪物防御的伤害
			// 刮死怪物需要的轮数
			for (int atk = y_damage; atk <= hp_m; atk++) {
				int round = hp_m / atk;
				if (hp_m % atk) {
					round++;
				}
				// cout << "Y_atk = " << atk << ' ' << round << '\n';
				// cout << "Y_def = " << def_y + def << '\n';
				int dif = (round * m_damage - hp_y);	
				if (dif >= 0) {
					cost_h = (dif + 1) * h;
				} else {
					cost_h = 0;
				}
				ans = min(ans, cost_d + cost_a + cost_h);
				cost_a += a;
			}	
			
		} else {
			// 满防御随便刮
			int y_damage = atk_y - def_m;
			if (y_damage <= 0) {
				cost_a += (-y_damage + 1) * a;
				y_damage = 1;
			}
			ans = min(ans, cost_d + cost_a);
		}
	}
	
	cout << ans;
    return 0;
}
