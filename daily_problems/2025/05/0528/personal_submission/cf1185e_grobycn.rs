//! core logic only
//! submission: https://codeforces.com/problemset/submission/1185/321800651
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let sheet: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut left = [usize::MAX; 26];
    let mut right = [0; 26];
    let mut top = [usize::MAX; 26];
    let mut down = [0; 26];
    for (r, row) in sheet.iter().enumerate() {
        for (c, &b) in row.iter().enumerate() {
            if b == b'.' {
                continue;
            }
            let idx = (b - b'a') as usize;
            left[idx] = left[idx].min(c);
            right[idx] = right[idx].max(c);
            top[idx] = top[idx].min(r);
            down[idx] = down[idx].max(r);
        }
    }
    let mut snakes = Vec::with_capacity(26);
    for (i, (((&l, &r), &t), &d)) in left.iter().zip(&right).zip(&top).zip(&down).enumerate() {
        if l == usize::MAX {
            continue;
        }
        if l != r && t != d {
            return Err("NO");
        }
        while snakes.len() < i + 1 {
            snakes.push((t + 1, l + 1, d + 1, r + 1));
        }
    }
    let mut got = vec![vec![b'.'; m]; n];
    for (&(t, l, d, r), sym) in snakes.iter().zip(b'a'..=b'z') {
        for i in t - 1..=d - 1 {
            for j in l - 1..=r - 1 {
                got[i][j] = sym;
            }
        }
    }
    if sheet != got {
        return Err("NO");
    }
    Ok("YES"
        .cr()
        .then(snakes.len())
        .cr()
        .then(Sep::<_, '\n'>(snakes)))
}
