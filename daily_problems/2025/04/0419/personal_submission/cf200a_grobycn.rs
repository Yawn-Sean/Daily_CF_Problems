//! core logic only
//! submission: https://codeforces.com/problemset/submission/200/316257036
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut vis = vec![vec![false; m]; n];
    let mut ufr = vec![UnionFind::new(m); n];
    let mut ufc = UnionFind::new(n);
    let mut cntr = vec![0; n];

    let ans: Vec<_> = scanner
        .iter::<(usize, usize)>(k)
        .map(|(mut x, mut y)| {
            (x, y) = (x - 1, y - 1);
            let mut dist = n + m;
            let mut seat = (usize::MAX, usize::MAX);
            let mut row = x;
            while row <= x && x - row <= dist {
                if !vis[row][y] {
                    seat = (row, y);
                    dist = x - row;
                    break;
                }
                let uf = &mut ufr[row];
                let p = uf.find(y);
                let r = uf.right[p];
                if r + 1 < m && x - row + r + 1 - y <= dist {
                    dist = x - row + r + 1 - y;
                    seat = (row, r + 1);
                }
                let l = uf.left[p];
                if l > 0 && x - row + y + 1 - l <= dist {
                    dist = x - row + y + 1 - l;
                    seat = (row, l - 1);
                }

                let p = ufc.find(row);
                row = ufc.left[p].wrapping_sub(1);
            }

            row = x;
            while row < n && row - x < dist {
                if !vis[row][y] {
                    seat = (row, y);
                    break;
                }
                let uf = &mut ufr[row];
                let p = uf.find(y);
                let r = uf.right[p];
                let l = uf.left[p];
                if l > 0 && row - x + y + 1 - l < dist {
                    dist = row - x + y + 1 - l;
                    seat = (row, l - 1);
                }
                if r + 1 < m && row - x + r + 1 - y < dist {
                    dist = row - x + r + 1 - y;
                    seat = (row, r + 1);
                }

                let p = ufc.find(row);
                row = ufc.right[p] + 1;
            }

            let (row, col) = seat;
            vis[row][col] = true;
            if col > 0 && vis[row][col - 1] {
                ufr[row].union(col - 1, col);
            }
            if col + 1 < m && vis[row][col + 1] {
                ufr[row].union(col, col + 1);
            }
            cntr[row] += 1;
            if cntr[row] == m {
                if row > 0 && cntr[row - 1] == m {
                    ufc.union(row - 1, row);
                }
                if row + 1 < n && cntr[row + 1] == m {
                    ufc.union(row, row + 1);
                }
            }
            (row + 1, col + 1)
        })
        .collect();
    Sep::<_, '\n'>(ans)
}

#[derive(Clone)]
struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
            left: (0..n).collect(),
            right: (0..n).collect(),
        }
    }
    fn find(&mut self, i: usize) -> usize {
        if i == self.parent[i] {
            return i;
        }
        self.parent[i] = self.find(self.parent[i]);
        self.parent[i]
    }
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] > self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            let l = self.left[xp.min(yp)];
            let r = self.right[xp.max(yp)];
            self.size[yp] += self.size[xp];
            self.parent[xp] = yp;
            self.left[yp] = l;
            self.right[yp] = r;
        }
    }
}
