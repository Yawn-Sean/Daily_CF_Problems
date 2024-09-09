//! core logic only
//! submission: https://codeforces.com/problemset/submission/838/280206445
const MULTIPLE_TEST: bool = false;

struct Sum(i64, i64);

impl Semigroup for Sum {
    fn append(&self, rhs: &Self) -> Self {
        Sum(self.0 + rhs.0, self.0 + rhs.0)
    }
}

impl Monoid for Sum {
    const IDENTITY: Self = Sum(0, 0);
}

#[derive(PartialEq)]
struct Inc(i64);

impl Semigroup for Inc {
    fn append(&self, rhs: &Self) -> Self {
        Inc(self.0 + rhs.0)
    }
}

impl Monoid for Inc {
    const IDENTITY: Self = Inc(0);
}

impl LazyUpdate<Sum> for Inc {
    fn update(&self, data: &Sum) -> Sum {
        Sum(self.0 * data.1 + data.0, data.1)
    }
}

struct Min(i64);

impl Semigroup for Min {
    fn append(&self, rhs: &Self) -> Self {
        Min(self.0.min(rhs.0))
    }
}

impl Monoid for Min {
    const IDENTITY: Self = Min(i64::MAX);
}

impl LazyUpdate<Min> for Inc {
    fn update(&self, data: &Min) -> Min {
        Min(data.0 + self.0)
    }
}

fn dfs(
    adj: &[Vec<usize>],
    edges: &[(usize, usize, i64)],
    cur: usize,
    enter: &mut [usize],
    leave: &mut [usize],
    clock: &mut usize) 
{
    enter[cur] = *clock;
    *clock += 1;
    for &eidx in &adj[cur] {
        let next = edges[eidx].1 - 1;
        dfs(adj, edges, next, enter, leave, clock);
    }
    leave[cur] = *clock;
}

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut edges: Vec<_> = scanner.iter::<(usize, usize, i64)>(2 * n - 2).collect();
    let mut adj = vec![vec![]; n];
    for (i, &(a, ..)) in edges.iter().enumerate().take(n - 1) {
        adj[a - 1].push(i);
    }
    let mut enter = vec![0; n];
    let mut leave = vec![0; n];
    dfs(&adj, &edges, 0, &mut enter, &mut leave, &mut 0);

    let is_ancient = |i: usize, p: usize| enter[p] <= enter[i] && leave[i] <= leave[p];

    let mut tr: LazySegmentTree::<Sum, Inc> = std::iter::repeat_with(|| Sum(0, 1)).take(n).collect();
    let mut tr2: LazySegmentTree::<Min, Inc> = std::iter::repeat_with(|| Min(0)).take(n).collect();
    for &(_, b, c) in &edges[..n - 1] {
        let b = b - 1;
        let (l, r) = (enter[b], leave[b]);
        tr.update(l, r, Inc(c));
        tr2.update(l, r, Inc(c));
    }

    for &(a, _, c) in &edges[n - 1..] {
        let idx = enter[a - 1];
        tr2.update(idx, idx + 1, Inc(c));
    }

    let mut ans = vec![];
    for _ in 0..q {
        if u8::from_scanner(scanner) == 1 {
            let (i, w) = <(usize, i64)>::from_scanner(scanner);
            let e = &mut edges[i - 1];
            let d = w - e.2;
            e.2 = w;
            if i < n {
                let b = e.1 - 1;
                let (l, r) = (enter[b], leave[b]);
                tr.update(l, r, Inc(d));
                tr2.update(l, r, Inc(d));
            } else {
                let a = e.0 - 1;
                let idx = enter[a];
                tr2.update(idx, idx + 1, Inc(d));
            }
        } else {
            let (mut u, mut v) = <(usize, usize)>::from_scanner(scanner);
            (u, v) = (u - 1, v - 1);
            let du = tr.query(enter[u], enter[u] + 1).0;
            let dv = tr.query(enter[v], enter[v] + 1).0;
            if is_ancient(v, u) {
                ans.push(dv - du);
            } else {
                let d = tr2.query(enter[u], leave[u]).0 - du + dv;
                ans.push(d);
            }
        }
    }
    Sep::<_, '\n'>(ans)
}

trait Semigroup {
    fn append(&self, rhs: &Self) -> Self;
}

trait Monoid: Semigroup {
    const IDENTITY: Self;
}

trait LazyUpdate<Data>: Monoid {
    fn update(&self, data: &Data) -> Data;
}

struct LazySegmentTree<Data, Todo> {
    n: usize,
    h: usize,
    data: Vec<Data>,
    todo: Vec<Todo>,
}

impl<Data, Todo> FromIterator<Data> for LazySegmentTree<Data, Todo>
where
    Data: Monoid,
    Todo: LazyUpdate<Data>,
{
    fn from_iter<T: IntoIterator<Item = Data>>(items: T) -> Self {
        let mut data = items.into_iter().collect::<Vec<_>>();
        let n = data.len();
        let h = std::mem::size_of_val(&n) * 8 - n.leading_zeros() as usize;
        data.resize_with(2 * n, || Data::IDENTITY);
        for i in 0..n {
            data.swap(i, i + n);
        }
        for i in (1..n).rev() {
            data[i] = data[i << 1].append(&data[(i << 1) | 1]);
        }
        let todo = std::iter::repeat_with(|| Todo::IDENTITY).take(n).collect();
        Self { n, h, data, todo }
    }
}

impl<Data, Todo> LazySegmentTree<Data, Todo>
where
    Data: Monoid,
    Todo: PartialEq + LazyUpdate<Data>,
{
    fn apply(&mut self, i: usize, todo: &Todo) {
        self.data[i] = todo.update(&self.data[i]);
        if i < self.n {
            self.todo[i] = todo.append(&self.todo[i]);
        }
    }
    fn push_down(&mut self, i: usize) {
        let mut s = self.h;
        while s > 0 {
            let p = i >> s;
            if self.todo[p] != Todo::IDENTITY {
                let todo = std::mem::replace(&mut self.todo[p], Todo::IDENTITY);
                self.apply(p << 1, &todo);
                self.apply((p << 1) | 1, &todo);
            }
            s -= 1;
        }
    }
    fn build(&mut self, mut i: usize) {
        while i > 1 {
            i >>= 1;
            self.data[i] = self.todo[i].update(
                &self.data[i << 1].append(&self.data[(i << 1) | 1]),
            );
        }
    }
    fn update(&mut self, mut l: usize, mut r: usize, todo: Todo) {
        (l, r) = (l + self.n, r + self.n);
        let (l0, r0) = (l, r);
        while l < r {
            if l & 1 != 0 {
                self.apply(l, &todo);
                l += 1;
            }
            if r & 1 != 0 {
                r -= 1;
                self.apply(r, &todo);
            }
            l >>= 1;
            r >>= 1;
        }
        self.build(l0);
        self.build(r0 - 1);
    }
    fn query(&mut self, mut l: usize, mut r: usize) -> Data {
        (l, r) = (l + self.n, r + self.n);
        let (mut f, mut b) = (Data::IDENTITY, Data::IDENTITY);
        self.push_down(l);
        self.push_down(r - 1);
        while l < r {
            if l & 1 != 0 {
                f = f.append(&self.data[l]);
                l += 1;
            }
            if r & 1 != 0 {
                r -= 1;
                b = self.data[r].append(&b);
            }
            l >>= 1;
            r >>= 1;
        }
        f.append(&b)
    }
}
