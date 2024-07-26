// core logic only
// submission: https://codeforces.com/problemset/submission/597/270676091
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<_> = scanner.iter(n).map(|x: usize| x - 1).collect();
    let mut dp = vec![1; n];

    (1..=k).for_each(|_| {
        let mut tr = Fenwick::new(n);
        for (i, &x) in a.iter().enumerate() {
            tr.inc(x, dp[i]);
            dp[i] = tr.sum(x);
        }
    });

    dp.into_iter().sum::<usize>()
}

struct Fenwick {
    arr: Vec<usize>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn sum(&self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    fn inc(&mut self, mut i: usize, d: usize) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += !i & (i + 1);
        }
    }
}
