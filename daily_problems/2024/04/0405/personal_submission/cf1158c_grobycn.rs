// core logic only
// submission: https://codeforces.com/problemset/submission/1158/255493358
const MULTIPLE_TEST: bool = true;

fn solver(next: Vec<i32>) -> impl Printable {
    let n = next.len();
    let mut st = vec![n + 1];
    let mut ans = Vec::with_capacity(n);

    for (&j, i) in next.iter().zip(1..) {
        while matches!(st.last(), Some(&r) if r <= i) {
            st.pop();
        }
        let gtcnt = st.len() - 1;
        let mut r = st[gtcnt];
        if j != -1 {
            let j = j as usize;
            if j > r {
                return Err(-1);
            }
            r = j;
            st.push(j);
        } else {
            st.push(r);
        }
        ans.push(r - gtcnt - 1);
    }

    Ok(Sep::<_, ' '>(ans))
}
