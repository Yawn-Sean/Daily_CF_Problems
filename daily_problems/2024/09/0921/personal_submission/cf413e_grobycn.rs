//! core logic only
//! submission: https://codeforces.com/problemset/submission/413/282218459
const MULTIPLE_TEST: bool = false;
const INF: i64 = i64::MAX / 2;

struct Distance {
    dist: [[i64; 2]; 2],
}

trait Semigroup {
    fn append(&self, rhs: &Self) -> Self;
}

trait Monoid: Semigroup {
    const IDENTITY: Self;
}

impl Semigroup for Distance {
    fn append(&self, rhs: &Self) -> Self {
        Distance {
            dist: [
                [
                    (self.dist[0][0] + 1 + rhs.dist[0][0]).min(self.dist[0][1]+ 1 + rhs.dist[1][0]).min(INF),
                    (self.dist[0][0] + 1 + rhs.dist[0][1]).min(self.dist[0][1]+ 1 + rhs.dist[1][1]).min(INF)
                ],
                [
                    (self.dist[1][0] + 1 + rhs.dist[0][0]).min(self.dist[1][1]+ 1 + rhs.dist[1][0]).min(INF),
                    (self.dist[1][0] + 1 + rhs.dist[0][1]).min(self.dist[1][1]+ 1 + rhs.dist[1][1]).min(INF)
                ],
            ]
        }
    }
}

impl Monoid for Distance {
    const IDENTITY: Self = Distance { dist: [[-1, INF], [INF, -1]] };
}

struct SegmentTree<M> {
    nodes: Vec<M>
}

impl<M: Monoid> FromIterator<M> for SegmentTree<M> {
    fn from_iter<I: IntoIterator<Item = M>>(items: I) -> Self {
        let mut nodes: Vec<_> = items.into_iter().collect();
        let n = nodes.len();
        nodes.resize_with(n * 2, || M::IDENTITY);
        for i in 0..n {
            nodes.swap(i, i + n);
        }
        for i in (1..n).rev() {
            nodes[i] = nodes[i << 1].append(&nodes[(i << 1) | 1]);
        }
        Self { nodes }
    }
}

impl<M: Monoid> SegmentTree<M> {
    fn query(&self, mut l: usize, mut r: usize) -> M {
        let n = self.nodes.len() / 2;
        (l, r) = (l + n, r + n);
        let (mut front, mut back) = (M::IDENTITY, M::IDENTITY);
        while l < r {
            if l & 1 != 0 {
                front = front.append(&self.nodes[l]);
                l += 1;
            }
            if r & 1 != 0 {
                r -= 1;
                back = self.nodes[r].append(&back);
            }
            l >>= 1;
            r >>= 1;
        }
        front.append(&back)
    }
}

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let maze: Vec<_> = scanner.iter::<String>(2).map(|r| r.into_bytes()).collect();
    let tree: SegmentTree<_> = (0..n).map(|i| {
        let dist = match (maze[0][i] == b'X', maze[1][i] == b'X') {
            (true, true) => [[INF; 2]; 2],
            (true, false) => [[INF; 2], [INF, 0]],
            (false, true) => [[0, INF], [INF; 2]],
            _ => [[0, 1], [1, 0]],
        };
        Distance { dist }
    }).collect();

    let coordinate = |idx: usize| (usize::from(idx > n), (idx - 1) % n);
    let ans: Vec<_> = scanner.iter::<(usize, usize)>(m)
        .map(|(u, v)| {
            let (mut ur, mut uc) = coordinate(u);
            let (mut vr, mut vc) = coordinate(v);
            if uc > vc {
                std::mem::swap(&mut ur, &mut vr);
                std::mem::swap(&mut uc, &mut vc);
            }
            let d = tree.query(uc, vc + 1).dist[ur][vr];
            if d >= INF { -1 } else { d }
        }).collect();
    Sep::<_, '\n'>(ans)
}
