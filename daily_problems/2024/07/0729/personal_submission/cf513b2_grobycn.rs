//! core logic only
//! submission: https://codeforces.com/problemset/submission/513/273352293
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize) -> impl Printable {
    fn solve(n: usize, m: usize) -> Vec<u8> {
        if n == 1 {
            return vec![1];
        }

        let half = 1 << (n - 2);
        if m > half {
            solve(n - 1, m - half)
                .into_iter()
                .map(|x| x + 1)
                .chain([1])
                .collect()
        } else {
            Some(1)
                .into_iter()
                .chain(solve(n - 1, m).into_iter().map(|x| x + 1))
                .collect()
        }
    }

    Sep::<_, ' '>(solve(n, m))
}
