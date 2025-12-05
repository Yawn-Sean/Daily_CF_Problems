#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <iomanip>

using namespace std;

// 使用 long double 来保证计算精度
using CostType = long double;

// 定义结构体来封装交易操作
struct TradeOperation {
    CostType a, b, c; 
    int x, y, z;        
};

class CoffeeMaximizerSolver {
private:
    int n, m;           
    CostType v;      
    string initial_state; 
    vector<TradeOperation> trades; 
    vector<CostType> min_cost; 

    void read_input() {
        long long v_ll; 
        if (!(cin >> n >> m >> v_ll)) return;
        v = (CostType)v_ll;

        cin >> initial_state;

        trades.resize(m);
        for (auto& op : trades) {
            int a_int, x_in, b_int, y_in, c_int, z_in;
            cin >> a_int >> x_in >> b_int >> y_in >> c_int >> z_in;
            
            op.a = (CostType)a_int;
            op.b = (CostType)b_int;
            op.c = (CostType)c_int;
            
            op.x = x_in - 1;
            op.y = y_in - 1;
            op.z = z_in - 1;
        }
    }

    void initialize_costs() {
        min_cost.assign(n, -1.0);
        
        for (int i = 0; i < n; ++i) {
            if (initial_state[i] == '1') {
                min_cost[i] = 1.0;
            }
        }
    }

    void compute_min_costs() {
        for (int iteration = 0; iteration < n; ++iteration) {
            for (const auto& op : trades) {
                if (min_cost[op.x] >= 0.0 && min_cost[op.y] >= 0.0) {
                    
                    CostType total_input_cost = op.a * min_cost[op.x] + op.b * min_cost[op.y];
                    CostType cost_to_get_one_z = total_input_cost / op.c;

                    if (min_cost[op.z] < 0.0) {
                        min_cost[op.z] = cost_to_get_one_z;
                    } 
                    else {
                        min_cost[op.z] = min(min_cost[op.z], cost_to_get_one_z);
                    }
                }
            }
        }
    }

    void print_result() {
        if (min_cost[0] < 0.0) {
            cout << 0 << '\n';
        } 
        else {
            cout << v / min_cost[0] << '\n';
        }
    }

public:
    void solve() {
        read_input();
        initialize_costs();
        compute_min_costs();
        print_result();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0; 

    cout << fixed << setprecision(10);

    while (t--) {
        CoffeeMaximizerSolver problem_solver;
        problem_solver.solve();
    }

    return 0;
}
