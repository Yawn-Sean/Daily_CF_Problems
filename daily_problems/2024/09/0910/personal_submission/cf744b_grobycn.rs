//! core logic only
//! submission: https://codeforces.com/problemset/submission/744/280586342
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::fmt::Write;
    let mut subset = vec![false; n];
    let mut ask = |block_size: usize, rev: usize| {
        let mut cnt = 0;
        for (i, ck) in subset.chunks_mut(block_size).enumerate() {
            let inset = i & 1 == rev;
            ck.iter_mut().for_each(|x| *x = inset);
            if inset {
                cnt += ck.len();
            }
        }
        println!("{cnt}");
        let mut ws = String::new();
        for (&inset, i) in subset.iter().zip(1..) {
            if inset {
                if ws.is_empty() {
                    write!(&mut ws, "{i}");
                } else {
                    write!(&mut ws, " {i}");
                }
            }
        }
        println!("{ws}");
        scanner.iter(n).collect::<Vec<i32>>()
    };

    let mut block_size = 1;
    let mut ans = vec![i32::MAX; n];
    while block_size < n {
        let info = [ask(block_size, 0), ask(block_size, 1)];
        for (i, x) in ans.iter_mut().enumerate() {
            let zero_at = (i / block_size) & 1;
            *x = info[1 - zero_at][i].min(*x);
        }
        block_size <<= 1;
    }

    (-1).cr().then(Sep::<_, ' '>(ans))
}
