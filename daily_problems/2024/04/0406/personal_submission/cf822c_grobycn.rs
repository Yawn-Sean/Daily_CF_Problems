// core logic only
// submission: https://codeforces.com/contest/822/submission/255285831
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, x: usize, scanner: &mut Scanner) -> impl Printable {
    let mut groups = vec![vec![]; x];
    for (l, r, c) in scanner.iter::<(usize, usize, i32)>(n) {
        let len = r + 1 - l;
        if len < x {
            groups[len].push((l, c));
        }
    }
    let mut ans = i32::MAX;
    groups.iter_mut().for_each(|g| g.sort_unstable());
    for y in 1..x {
        let z = x - y;
        let gy = &groups[y];
        let gz = &groups[z];
        if gy.is_empty() || gz.is_empty() {
            continue;
        }
        let mut i = 0;
        let mut mn = i32::MAX;
        for &(l, c) in gy.iter() {
            while i < gz.len() && gz[i].0 + z <= l {
                mn = mn.min(gz[i].1);
                i += 1;
            }
            if mn != i32::MAX {
                ans = ans.min(mn + c);
            }
        }
    }
    if ans == i32::MAX {
        -1
    } else {
        ans
    }
}
