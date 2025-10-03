#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        ll p;
        cin >> p;
        
        unordered_set<int> unique_answers;
        
        for (int b = 1; b <= 1000000; b++) {
            bool condition1 = ((p - 1) % (b + 1) == 0);
            bool condition2 = (2 * (p - 1) % (b + 2) == 0);
            
            if (condition1 && condition2) {
                unique_answers.insert(b);
            }
        }
        
        for (int k = 1; k <= 2000000; k++) {
            if (2 * (p - 1) % k == 0) {
                ll value = 2 * (p - 1) / k;
                ll discriminant = 4 * value + 1;
                
                ll root = sqrtl(discriminant);
                
                while (root * root < discriminant) root++;
                while (root * root > discriminant) root--;
                
                ll candidate_b = (root - 1) / 2 - 1;
                
                if (candidate_b > 0 && candidate_b <= 1e12) {
                    bool condition1 = ((p - 1) % (candidate_b + 1) == 0);
                    bool condition2 = (2 * (p - 1) % (candidate_b + 2) == 0);
                    
                    if (condition1 && condition2) {
                        unique_answers.insert(candidate_b);
                    }
                }
            }
        }
        
        vector<int> sorted_answers(unique_answers.begin(), unique_answers.end());
        sort(sorted_answers.begin(), sorted_answers.end());
        
        cout << sorted_answers.size() << '\n';
        for (size_t i = 0; i < sorted_answers.size(); i++) {
            cout << sorted_answers[i] << (i + 1 < sorted_answers.size() ? " " : "");
        }
        cout << '\n';
    }
    
    return 0;
}
