// core logic only
// submission: https://codeforces.com/contest/1148/submission/263149403
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut p = Vec::with_capacity(n);
    let mut pos = vec![0; n];
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        p.push(x - 1);
        pos[x - 1] = i;
    }

    let h = n / 2;
    let mut ans = vec![];
    for i in 0..n {
        let j = pos[i];
        if j == i {
            continue;
        }
        let l = ans.len();
        if j - i >= h {
            ans.push((i, j));
        } else if i >= h {
            ans.push((j, 0));
            ans.push((0, i));
            ans.push((j, 0));
        } else if j < h {
            ans.push((j, n - 1));
            ans.push((n - 1, i));
        } else {
            ans.push((j, 0));
            ans.push((0, n - 1));
            ans.push((n - 1, i));
            ans.push((j, 0));
        }
        for &(i, j) in ans[l..].iter() {
            p.swap(i, j);
            pos.swap(p[i], p[j]);
        }
    }

    ans.len()
        .cr()
        .then(Sep::<_, '\n'>(ans.into_iter().map(|(x, y)| (x + 1, y + 1))))
}
