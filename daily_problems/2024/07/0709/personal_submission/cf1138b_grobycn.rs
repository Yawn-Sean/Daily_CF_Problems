// core logic only
// submission: https://codeforces.com/problemset/submission/1138/269596746
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, c: String, a: String) -> impl Printable {
    let cnt = c.bytes().filter(|&c| c == b'1').count();
    let mut indices = vec![vec![]; 3];
    for (i, (ai, ci)) in a.bytes().zip(c.bytes()).enumerate() {
        indices[(ai - b'0' + ci - b'0') as usize].push(i + 1);
    }

    let half = n / 2;
    for cnt2 in 0..=indices[2].len() {
        if let Some(cnt1) = cnt.checked_sub(cnt2 * 2) {
            if cnt1 > indices[1].len() {
                continue;
            }
            if let Some(cnt0) = half.checked_sub(cnt1 + cnt2) {
                if cnt0 > indices[0].len() {
                    continue;
                }
                let mut ans = Vec::with_capacity(half);
                ans.extend(indices[2][cnt2..].iter().copied());
                ans.extend(indices[1][cnt1..].iter().copied());
                ans.extend(indices[0][cnt0..].iter().copied());
                return Ok(Sep::<_, ' '>(ans));
            }
        }
    }

    Err(-1)
}
