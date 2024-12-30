// core logic only
// submission: https://codeforces.com/problemset/submission/1609/260260935
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, d: usize, scanner: &mut Scanner) -> impl Printable {
    let mut uf = UnionFind::new(n);
    let mut rem = 1;
    let ans: Vec<_> = scanner
        .iter::<(usize, usize)>(d)
        .map(|(x, y)| {
            if !uf.union(x - 1, y - 1) {
                rem += 1;
            }
            let mut rem = rem;
            let mut ans = 0;
            for sz in (1..=n).rev() {
                let cnt = rem.min(uf.size_count[sz]);
                ans += cnt * sz;
                rem -= cnt;
                if rem == 0 {
                    break;
                }
            }
            ans - 1
        })
        .collect();
    Sep::<_, '\n'>(ans)
}

struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    size_count: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let mut size_count = vec![0; n + 1];
        size_count[1] = n;
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
            size_count,
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x == self.parent[x] {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }
    fn union(&mut self, x: usize, y: usize) -> bool {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] < self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            self.size_count[self.size[xp]] -= 1;
            self.size_count[self.size[yp]] -= 1;
            self.size[xp] += self.size[yp];
            self.size_count[self.size[xp]] += 1;
            self.parent[yp] = xp;
            true
        } else {
            false
        }
    }
}
