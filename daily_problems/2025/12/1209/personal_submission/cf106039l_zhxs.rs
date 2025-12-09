use std::io::prelude::*;

pub struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: std::str::SplitAsciiWhitespace<'static>,
}

impl<R: BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: Vec::new(),
            buf_iter: "".split_ascii_whitespace(),
        }
    }
    pub fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = std::str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let mut k: usize = scanner.next();
    let mut g = vec![vec![b'0'; n]; n];
    for i in 0..n {
        let line: String = scanner.next();
        g[i] = line.into_bytes();
    }
    let len = n * n;
    let mut m = vec![vec![0; len]; len];

    let f = |i, j| i * n + j;

    let mul = |a: &Vec<Vec<usize>>, b: &Vec<Vec<usize>>| -> Vec<Vec<usize>> {
        let mut c = vec![vec![0; len]; len];
        for i in 0..len {
            for j in 0..len {
                for p in 0..len {
                    c[i][j] ^= a[i][p] * b[p][j];
                }
            }
        }
        c
    };

    for i in 0..n {
        for j in 0..n {
            if g[i][j] == b'#' {
                continue;
            }
            for di in -1..=1 {
                for dj in -1..=1 {
                    let ni = i as isize + di;
                    let nj = j as isize + dj;
                    if ni < 0 || ni >= n as isize || nj < 0 || nj >= n as isize {
                        continue;
                    }
                    m[f(i, j)][f(ni as usize, nj as usize)] = 1;
                }
            }
        }
    }

    let mut res = vec![vec![0; len]; len];
    for i in 0..len {
        res[i][i] = 1;
    }

    while k > 0 {
        if k & 1 > 0 {
            res = mul(&res, &m);
        }
        m = mul(&m, &m);
        k >>= 1;
    }

    let mut ans = vec![vec![0; n]; n];
    for x in 0..len {
        let (i, j) = (x / n, x % n);
        if g[i][j] == b'#' {
            continue;
        }
        for y in 0..len {
            let (ni, nj) = (y / n, y % n);
            if res[x][y] == 1 && g[ni][nj] != b'#' {
                ans[i][j] ^= g[ni][nj] - b'0';
            }
        }
    }

    for i in 0..n {
        for j in 0..n {
            if g[i][j] == b'#' {
                print!("#");
            } else {
                print!("{}", ans[i][j]);
            }
        }
        println!();
    }
}
