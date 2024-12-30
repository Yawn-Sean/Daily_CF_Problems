// core logic only
// submission: https://codeforces.com/contest/631/submission/258978402
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<i32> = scanner.iter(n).collect();
    let mut st = vec![];
    for (t, r) in scanner.iter::<(u8, usize)>(m) {
        while matches!(st.last(), Some(&(_, i)) if i <= r) {
            st.pop();
        }
        st.push((t, r));
    }
    st.dedup_by(|r, l| r.0 == l.0);
    let mut r = st[0].1;
    let mut xs: Vec<_> = a[..r].iter().copied().collect();
    xs.sort_unstable();
    let mut xs = xs.into_iter();
    let mut it = a[..r].iter_mut().rev();
    for w in st.windows(2) {
        let d = w[0].1 - w[1].1;
        if w[0].0 == 1 {
            (0..d).for_each(|_| {
                *it.next().unwrap() = xs.next_back().unwrap();
            });
        } else {
            (0..d).for_each(|_| {
                *it.next().unwrap() = xs.next().unwrap();
            });
        }
    }
    if let Some(&(t, r)) = st.last() {
        if t == 1 {
            (0..r).for_each(|_| {
                *it.next().unwrap() = xs.next_back().unwrap();
            });
        } else {
            (0..r).for_each(|_| {
                *it.next().unwrap() = xs.next().unwrap();
            });
        }
    }
    Sep::<_, ' '>(a)
}
