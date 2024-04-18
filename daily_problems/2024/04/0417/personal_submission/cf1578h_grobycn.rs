// core logic only
// submission: https://codeforces.com/problemset/submission/1578/257028311
const MULTIPLE_TEST: bool = false;

fn solver(expr: String) -> impl Printable {
    enum Token {
        LeftParen,
        Order(usize),
    }

    let mut st = vec![];
    for b in expr.bytes() {
        match b {
            b'(' => st.push(Token::LeftParen),
            b'-' => {
                if let Some(Token::Order(x)) = st.last_mut() {
                    *x += 1;
                }
            }
            b')' => {
                let mut mx = 0;
                while let Some(Token::Order(x)) = st.pop() {
                    mx = mx.max(x);
                }
                st.push(Token::Order(mx));
            }
            _ => {}
        }
    }
    let mut ans = 0;
    while let Some(Token::Order(x)) = st.pop() {
        ans = ans.max(x);
    }
    ans
}
