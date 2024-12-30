// core logic only
// submission: https://codeforces.com/contest/1267/submission/258727467
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; n];
    scanner.iter(n).for_each(|c: usize| {
        count[c - 1] += 1;
    });

    let count: Vec<_> = count.into_iter().filter(|&c| c != 0).collect();
    let mn = *count.iter().min().unwrap();

    'outter: for sz in (2..=mn.max(2)).rev() {
        let mut num = 0;
        for &cnt in &count {
            let q = cnt / sz;
            let r = cnt % sz;
            if r > q {
                continue 'outter;
            }
            let x = (q - r) / (sz + 1);
            num += q - x;
        }
        return num;
    }

    count.iter().map(|&c| (c + 1) / 2).sum()
}
