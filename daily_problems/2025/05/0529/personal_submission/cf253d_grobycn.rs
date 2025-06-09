//! core logic only
//! submission: https://codeforces.com/problemset/submission/253/322060436
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, _m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let table: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut ans = 0;
    for (t, first_row) in table.iter().enumerate() {
        let mut cnta: Vec<_> = first_row.iter().map(|&b| usize::from(b == b'a')).collect();
        for row in table[t + 1..].iter() {
            for (&b, cnt) in row.iter().zip(&mut cnta) {
                if b == b'a' {
                    *cnt += 1;
                }
            }
            let mut groups = vec![vec![]; 26];
            let mut sum = 0;
            for ((&first_letter, &last_letter), &cnt) in table[t].iter().zip(row).zip(&cnta) {
                if first_letter == last_letter {
                    groups[(first_letter - b'a') as usize].push((sum, sum + cnt));
                }
                sum += cnt;
            }
            for g in groups.iter() {
                let mut l = 0;
                for (r, &(_, sum)) in g.iter().enumerate() {
                    while l < r && sum - g[l].0 > k {
                        l += 1;
                    }
                    ans += r - l;
                }
            }
        }
    }
    ans
}
