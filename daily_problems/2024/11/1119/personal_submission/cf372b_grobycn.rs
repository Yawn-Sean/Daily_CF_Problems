//! core logic only
//! submission: https://codeforces.com/problemset/submission/372/292347329
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut grid: Vec<Vec<_>> = scanner
        .iter(n)
        .map(|s: String| s.bytes().map(|b| (b - b'0') as i32).collect())
        .collect();

    for r in 0..n {
        for c in 1..m {
            grid[r][c] += grid[r][c - 1];
        }
    }
    for r in 1..n {
        for c in 0..m {
            grid[r][c] += grid[r - 1][c];
        }
    }

    let mut is_good = vec![vec![vec![vec![0; m]; m]; n]; n];
    for minr in 0..n {
        for maxr in minr..n {
            for minc in 0..m {
                for maxc in minc..m {
                    let mut sum = grid[maxr][maxc];
                    if minc > 0 {
                        sum -= grid[maxr][minc - 1];
                    }
                    if minr > 0 {
                        sum -= grid[minr - 1][maxc];
                    }
                    if minc > 0 && minr > 0 {
                        sum += grid[minr - 1][minc - 1];
                    }
                    if sum == 0 {
                        is_good[n - 1 - minr][maxr][m - 1 - minc][maxc] = 1;
                    }
                }
            }
        }
    }

    for r1 in 0..n {
        for r2 in 0..n {
            for c1 in 0..m {
                for c2 in 1..m {
                    is_good[r1][r2][c1][c2] += is_good[r1][r2][c1][c2 - 1];
                }
            }
        }
    }
    for r1 in 0..n {
        for r2 in 0..n {
            for c1 in 1..m {
                for c2 in 0..m {
                    is_good[r1][r2][c1][c2] += is_good[r1][r2][c1 - 1][c2];
                }
            }
        }
    }
    for r1 in 0..n {
        for r2 in 1..n {
            for c1 in 0..m {
                for c2 in 0..m {
                    is_good[r1][r2][c1][c2] += is_good[r1][r2 - 1][c1][c2];
                }
            }
        }
    }
    for r1 in 1..n {
        for r2 in 0..n {
            for c1 in 0..m {
                for c2 in 0..m {
                    is_good[r1][r2][c1][c2] += is_good[r1 - 1][r2][c1][c2];
                }
            }
        }
    }

    let ans: Vec<usize> = scanner
        .iter::<(usize, usize, usize, usize)>(q)
        .map(|(a, b, c, d)| is_good[n - a][c - 1][m - b][d - 1])
        .collect();

    Sep::<_, '\n'>(ans)
}
