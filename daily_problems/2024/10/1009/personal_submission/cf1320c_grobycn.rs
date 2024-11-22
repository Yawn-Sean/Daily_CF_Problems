//! core logic only
//! submission: https://codeforces.com/problemset/submission/1320/285029353
const MULTIPLE_TEST: bool = false;

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

struct Max(i64);

impl Semigroup for Max {
    fn append(&self, rhs: &Self) -> Self {
        Max(self.0.max(rhs.0))
    }
}

impl Monoid for Max {
    const IDENTITY: Self = Max(i64::MIN);
}

impl LazyUpdate<Max> for Inc {
    fn update(&self, data: &Max) -> Max {
        Max(data.0 + self.0)
    }
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
            self.data[i] = self.todo[i].update(&self.data[i << 1].append(&self.data[(i << 1) | 1]));
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

fn solver(n: usize, m: usize, p: usize, scanner: &mut Scanner) -> impl Printable {
    let mut weapons: Vec<(i32, i64)> = scanner.iter(n).collect();
    let mut armors: Vec<(i32, i64)> = scanner.iter(m).collect();
    let mut monsters: Vec<(i32, i32, i64)> = scanner.iter(p).collect();
    weapons.sort_unstable();
    monsters.sort_unstable();
    armors.sort_unstable();
    let mut seg_tree: LazySegmentTree<Max, Inc> =
        armors.iter().map(|&(_, cbi)| Max(-cbi)).collect();
    let mut monsters = monsters.into_iter().peekable();
    let mut ans = i64::MIN;
    for (ai, cai) in weapons {
        while let Some((_, y, z)) = monsters.next_if(|&(x, ..)| x < ai) {
            let i = armors.partition_point(|a| a.0 <= y);
            if i < m {
                seg_tree.update(i, m, Inc(z));
            }
        }
        ans = ans.max(seg_tree.query(0, m).0 - cai);
    }
    ans
}
