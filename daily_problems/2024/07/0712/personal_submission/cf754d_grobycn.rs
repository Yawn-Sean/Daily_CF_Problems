// core logic only
// submission: https://codeforces.com/problemset/submission/754/270195174
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let segs: Vec<(i32, i32)> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| segs[i].0);

    let mut hp = BinaryHeap::with_capacity(k + 1);
    let mut ans = 0;
    let mut choose_l = i32::MAX;
    for (l, r) in indices.iter().map(|&i| segs[i]) {
        hp.push(Reverse(r));
        if hp.len() > k {
            hp.pop();
        }
        if hp.len() == k {
            let r = hp.peek().unwrap().0;
            if r >= l {
                let len = r + 1 - l;
                if len > ans {
                    ans = len;
                    choose_l = l;
                }
            }
        }
    }

    let choose_r = if ans == 0 {
        i32::MIN
    } else {
        choose_l + ans - 1
    };
    let indices = (1..=n)
        .filter(move |&i| {
            let (l, r) = segs[i - 1];
            l <= choose_l && choose_r <= r
        })
        .take(k);
    ans.cr().then(Sep::<_, ' '>(indices))
}
