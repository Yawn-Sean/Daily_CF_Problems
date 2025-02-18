struct FenwickTree {
    n: usize,
    data: Vec<i64>,
}
fn lowbit(x: usize) -> usize {
    x & x.wrapping_neg()
}
impl FenwickTree {
    fn new(n: usize) -> Self {
        Self {
            n,
            data: vec![0; n + 1],
        }
    }
    fn add(&mut self, i: usize, x: i64) {
        let mut i = i;
        while i <= self.n {
            // println!("add finished");
            // println!("{}", i);
            self.data[i] += x;
            i += lowbit(i);
        }
    }
    fn sum(&self, i: usize) -> i64 {
        let mut i = i;
        let mut res = 0;
        while i > 0 {
            res += self.data[i];
            i -= lowbit(i);
        }
        res
    }
    fn sum_range(&self, l: usize, r: usize) -> i64 {
        self.sum(r) - self.sum(l - 1)
    }
}
fn main() {
    input! {n: usize}
    input! {mut a: [i32; n]}
    a.insert(0, 0);

    let mut tasks = vec![];
    for v in 1..n {
        for k in 1..n {
            if k * (v - 1) + 2 > n {
                break;
            }
            tasks.push((k * (v - 1) + 2, n.min(k * v + 1), a[v], k));
        }
    }
    tasks.sort_unstable_by_key(|x| x.2);
    // println!("{:?}", tasks);
    let mut at = vec![];
    for i in 1..=n {
        at.push((i, a[i]));
    }

    at.sort_unstable_by_key(|x| -x.1);

    let mut ft = FenwickTree::new(n + 1);
    let mut res = vec![0; n + 1];
    for (a, b, c, d) in tasks {
        while !at.is_empty() && at[at.len() - 1].1 < c {
            // println!("{:?}", at);
            let (i, _) = at.pop().unwrap();
            ft.add(i, 1);
        }
        res[d] += ft.sum_range(a, b);
    }
    for i in 1..n {
        print!("{} ", res[i])
    }
}
