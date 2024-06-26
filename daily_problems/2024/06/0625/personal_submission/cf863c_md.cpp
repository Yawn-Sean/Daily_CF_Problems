// 0625
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 k;
    int a, b;
    std::cin >> k >> a >> b;
    a--; b--;
    std::vector<std::vector<int>> a_choice(3), b_choice(3);
    for (int i = 0; i < 3; ++i) {
        int a1, a2, a3;
        std::cin >> a1 >> a2 >> a3;
        a1--; a2--; a3--;
        a_choice[i] = {a1, a2, a3};
    }

    for (int i = 0; i < 3; ++i) {
        int b1, b2, b3;
        std::cin >> b1 >> b2 >> b3;
        b1--; b2--; b3--;  
        b_choice[i] = {b1, b2, b3};
    }

    std::vector<std::vector<int>> winner_id_mat = {
        {0, 2, 1},
        {1, 0, 2},
        {2, 1, 0}
    };
    
    std::vector<std::vector<i64>> acc_score(3, std::vector<i64>(1, 0));
    std::map<int, i64> visited;
    
    std::optional<int> last_cycle = std::nullopt;
    for (i64 i = 0; i < k; ++i) {
        if (visited.contains(a * 3 + b)) {
            last_cycle = i;
            break;
        } else {
            auto winner_id = winner_id_mat[a][b];
            acc_score[1].push_back(acc_score[1].back());
            acc_score[2].push_back(acc_score[2].back());
            ++acc_score[winner_id].back();
            visited[a * 3 + b] = i;
            std::tie(a, b) = make_pair(a_choice[a][b], b_choice[a][b]);
        }
    }

    if (last_cycle.has_value()) {
        i64 cycle_exit = last_cycle.value();
        i64 cycle_enter = visited[a * 3 + b];
        i64 cycle_len = cycle_exit - cycle_enter;
        i64 cycle_cnt = (k - cycle_enter)  / cycle_len;
        i64 cycle_remain = (k - cycle_enter) % cycle_len;
        auto calc_score = [&](auto& acc) {
            return acc[cycle_enter] + (acc[cycle_enter + cycle_remain] - acc[cycle_enter]) + cycle_cnt * (acc[cycle_exit] - acc[cycle_enter]);
        };
        std::cout << calc_score(acc_score[1]) << " " << calc_score(acc_score[2]) << std::endl;
    } else {
        std::cout << acc_score[1].back() << " " << acc_score[2].back() << std::endl;
    }

    return 0;
}