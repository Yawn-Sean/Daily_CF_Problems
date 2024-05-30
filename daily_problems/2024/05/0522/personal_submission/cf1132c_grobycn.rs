// core logic only
// submission: https://codeforces.com/problemset/submission/1132/262161119
const MULTIPLE_TEST: bool = false;

fn count_exact(count: &[i64], num_exact: i64) -> impl Fn(usize, usize) -> usize {
    let count: Vec<usize> = count
        .iter()
        .scan(0, |cnt, &c| {
            let ret = Some(*cnt);
            if c == num_exact {
                *cnt += 1;
            }
            ret
        })
        .collect();
    move |l: usize, r: usize| count[r] - count[l - 1]
}

fn solver(n: usize, painters: Vec<(usize, usize)>) -> impl Printable {
    let mut count = vec![0i64; n + 1];
    for &(l, r) in &painters {
        count[l - 1] += 1;
        count[r] -= 1;
    }
    for i in 1..=n {
        count[i] += count[i - 1];
    }
    let max = count.iter().filter(|&c| *c > 0).count();
    let count1 = count_exact(&count, 1);
    let count2 = count_exact(&count, 2);

    let mut ans = 0;
    for (i, &(li, ri)) in painters.iter().enumerate() {
        for &(lj, rj) in &painters[..i] {
            if rj < li || ri < lj {
                let painted = max - count1(li, ri) - count1(lj, rj);
                ans = ans.max(painted);
            } else {
                let l = li.max(lj);
                let r = ri.min(rj);
                let painted = max
                    - count2(l, r)
                    - count1(li, l - 1)
                    - count1(lj, l - 1)
                    - count1(r + 1, ri)
                    - count1(r + 1, rj);
                ans = ans.max(painted);
            }
        }
    }
    ans
}
