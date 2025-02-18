//! core logic only
//! submission: https://codeforces.com/problemset/submission/659/289453898
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<Vec<usize>> = (0..n).map(|_| scanner.iter(m).collect()).collect();
    let mut uf = UnionFind::new(n * m);
    let mut cells: Vec<_> = a
        .iter()
        .enumerate()
        .map(|(r, row)| row.iter().enumerate().map(move |(c, &x)| (x, r, c)))
        .flatten()
        .collect();
    cells.sort_unstable();

    for &(x, r, c) in cells.iter().rev() {
        let idx = r * m + c;
        for (i, j) in [
            (r.wrapping_sub(1), c),
            (r + 1, c),
            (r, c.wrapping_sub(1)),
            (r, c + 1),
        ] {
            if i < n && j < m && (a[i][j], i, j) > (x, r, c) {
                uf.union(idx, i * m + j);
            }
        }
        if k % x == 0 {
            let p = uf.find(idx);
            let sz = (-uf.parent_or_size[p]) as usize;
            if sz >= k / x {
                let mut ans = vec![vec![0; m]; n];
                let mut queue = std::collections::VecDeque::from([(r, c)]);
                ans[r][c] = x;
                let mut cnt = k / x - 1;
                while cnt > 0 {
                    let (r, c) = queue.pop_front().unwrap();
                    for (i, j) in [
                        (r.wrapping_sub(1), c),
                        (r + 1, c),
                        (r, c.wrapping_sub(1)),
                        (r, c + 1),
                    ] {
                        if i < n && j < m && ans[i][j] == 0 && a[i][j] >= x {
                            ans[i][j] = x;
                            cnt -= 1;
                            if cnt == 0 {
                                break;
                            }
                            queue.push_back((i, j));
                        }
                    }
                }
                return Ok("YES".cr().then(Mat(ans)));
            }
        }
    }
    Err("NO")
}

struct UnionFind {
    parent_or_size: Vec<i32>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent_or_size: vec![-1; n],
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if self.parent_or_size[x] < 0 {
            return x;
        }
        let p = self.find(self.parent_or_size[x] as usize) as usize;
        self.parent_or_size[x] = p as i32;
        p
    }
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp == yp {
            return;
        }
        if self.parent_or_size[xp] < self.parent_or_size[yp] {
            std::mem::swap(&mut xp, &mut yp);
        }
        self.parent_or_size[yp] += self.parent_or_size[xp];
        self.parent_or_size[xp] = yp as i32;
    }
}
