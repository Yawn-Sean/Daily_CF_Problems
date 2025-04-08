//! core logic only
//! submission: https://codeforces.com/problemset/submission/1938/314378311
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<u32>) -> impl Printable {
    let mut ans = (1 << a[0]) - 1;
    for (i, w) in a.windows(2).enumerate() {
        if w[0] + 1 < w[1] || w[1] == 0 {
            return Err(-1);
        }
        let d = w[0] + 1 - w[1];
        let t = (1 << d) - 1;
        let x = (((1usize << (w[0] - d)) - 1) << (d + 1)) | t;
        ans = ans.max(x.saturating_sub(i));
    }

    for (i, &ai) in a.iter().enumerate() {
        if (ans + i).count_ones() != ai {
            return Err(-1);
        }
    }
    Ok(ans)
}
