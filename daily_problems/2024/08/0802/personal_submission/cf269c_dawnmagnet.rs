fn main() {
    input! {n: usize, m: usize}
    input! {mut e: [(usize, usize, i32); m]}
    let mut res = vec![0; m];
    let mut c = vec![0; n];
    let mut child = vec![vec![]; n];
    for (i, (a, b, w)) in &mut e.iter_mut().enumerate() {
        *a -= 1;
        *b -= 1;
        c[*a] += *w;
        c[*b] += *w;
        child[*a].push(i);
        child[*b].push(i);
    }
    for i in &mut c[1..n - 1] {
        *i /= 2;
    }
    c[0] = 0;
    // println!("{c:?}");
    let mut s = vec![0];
    while let Some(u) = s.pop() {
        for &v in &child[u] {
            let d = e[v].0 ^ e[v].1 ^ u;
            if c[d] == 0 {
                continue;
            }
            // println!("{u}->{d}");
            res[v] = (u == e[v].1) as i32;
            c[d] -= e[v].2;
            if c[d] == 0 {
                s.push(d);
            }
        }
    }
    for i in res {
        println!("{}", i);
    }
}
