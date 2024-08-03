// submission link: https://codeforces.com/contest/1578/submission/257107119
#include<iostream>
#include<vector>
using namespace std;
void solve(string &s){
    int n = s.size();
    int ret = 0;
    vector<int> stack;
    int arrow = 1000;
    int right_parenthesis = 2000;
    int i = n -1;
    int degree = 0;
    while (i >= 0){
        if (s[i] == '('){
            if (stack.back() == right_parenthesis){
                stack.pop_back();
                degree = 0;
            }else {
                degree = stack.back();
                stack.pop_back();
                stack.pop_back();
            }
            while (!stack.empty()  && stack.back() == arrow){
                stack.pop_back();
                int another_degree = stack.back();
                stack.pop_back();
                degree = max(degree + 1, another_degree );
            }
            stack.push_back(degree);
            ret = max(ret, degree);
            --i;
        } else if (s[i] == ')'){
            stack.push_back(right_parenthesis);
            i--;
        } else if (s[i] == '>'){
            stack.push_back(arrow);
            i -= 2;
        }
    }
    cout << ret << endl;
    return;
}
int main(){
    string s;
    cin >> s;
    solve(s);
    return 0;
}
