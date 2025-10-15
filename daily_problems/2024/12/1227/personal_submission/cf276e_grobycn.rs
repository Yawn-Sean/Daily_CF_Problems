//! core logic only
//! submission: https://codeforces.com/problemset/submission/276/298671229
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        u -= 1;
        v -= 1;
        adj[u].push(v);
        adj[v].push(u);
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        fa: usize,
        depth: &mut [usize],
        enter: &mut [usize],
        leave: &mut [usize],
        clock: &mut usize,
    ) {
        enter[cur] = *clock;
        *clock += 1;
        let d = depth[cur] + 1;
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            depth[next] = d;
            dfs(adj, next, cur, depth, enter, leave, clock);
        }
        leave[cur] = *clock;
    }

    let mut depth = vec![0; n];
    let mut left = vec![0; n];
    let mut right = vec![0; n];
    dfs(&adj, 0, 0, &mut depth, &mut left, &mut right, &mut 0);

    let mut common = Fenwick::new(n);
    let mut unique = Fenwick::new(n);
    let mut ans = vec![];
    for _ in 0..q {
        if u8::from_scanner(scanner) == 0 {
            let (mut v, x, d) = <(usize, i64, usize)>::from_scanner(scanner);
            v -= 1;
            if depth[v] > d {
                let l = left[v] - d;
                let r = right[v].min(left[v] + d + 1);
                unique.add(l, x);
                unique.add(r, -x);
            } else {
                let d1 = d - depth[v];
                common.add(0, x);
                common.add(d - depth[v] + 1, -x);
                let l = left[v] + 1 + d - 2 * depth[v];
                let r = right[v].min(left[v] + d + 1);
                if l < r {
                    unique.add(l, x);
                    unique.add(r, -x);
                }
            }
        } else {
            let v = usize::from_scanner(scanner) - 1;
            let x = common.query_(depth[v] + 1) + unique.query_(left[v] + 1);
            ans.push(x);
        }
    }
    Sep::<_, '\n'>(ans)
}

struct Fenwick {
    arr: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn add(&mut self, mut i: usize, d: i64) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += (i + 1) & !i;
        }
    }
    fn query_(&self, mut r: usize) -> i64 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    fn query(&self, l: usize, r: usize) -> i64 {
        self.query_(r) - self.query_(l)
    }
}
