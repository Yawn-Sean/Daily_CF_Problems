/*
为了让所有严格前缀都不是合法括号序列，则最左边的左括号应该和最右边的右括号匹配
中间的需要保证自己是个合法串
? 优先填 )，然后反悔
*/

int T;
int n;
string s;

void solve1() {
    cin >> n >> s;
    if (s[0] == ')' || s[n - 1] == '(' || n % 2 != 0) {
        cout << ":(\n";
        return;
    }
    s[0] = '(';
    s[n - 1] = ')';

    int sum = 0;
    stack<int> right_question_pos;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '(') {
            sum++;
        } else if (s[i] == ')') {
            sum--;
            while (sum < 0 && !right_question_pos.empty()) {
                int pos = right_question_pos.top();
                right_question_pos.pop();
                s[pos] = '(';
                sum += 2;
            }
            if (sum < 0) {
                cout << ":(\n";
                return;
            }
        } else {
            if (sum > 0) {
                sum--;
                s[i] = ')';
                right_question_pos.push(i);
            } else {
                sum++;
                s[i] = '(';
            }
        }
    }
    while (sum < 0 && !right_question_pos.empty()) {
        int pos = right_question_pos.top();
        sum += 2;
        s[pos] = '(';
    }
    if (sum == 0) {
        cout << s << "\n";
    } else {
        cout << ":(\n";
    }
}      