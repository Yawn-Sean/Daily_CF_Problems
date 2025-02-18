fn main() {
    input! { n: usize, l: usize, r: usize }

    let mut t = 1;
    while t <= n {
        t *= 2;
    }
    let res = dfs(n, 1, t - 1, l, r);
    println!("{}", res);
}

fn dfs(n: usize, cl: usize, cr: usize, l: usize, r: usize) -> usize {
    if l <= cl && cr <= r {
        return n;
    }
    if r < cl || cr < l {
        return 0;
    }
    let mid = (cl + cr - 1) / 2;

    let res = dfs(n / 2, cl, mid, l, r)
        + dfs(n % 2, mid + 1, mid + 1, l, r)
        + dfs(n / 2, mid + 2, cr, l, r);
    // eprintln!("{} {} {} {}", n, cl, cr, res);
    res
}