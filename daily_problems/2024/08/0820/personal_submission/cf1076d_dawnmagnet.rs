fn main() {
    input! { n: usize, m: usize, k: usize }
    input! { mut edges: [(usize, usize, usize); m] }

    let mut paths: Vec<Vec<usize>> = vec![vec![]; n];
    for (i, (u, v, _)) in edges.iter_mut().enumerate() {
        *u -= 1;
        *v -= 1;
        paths[*u].push(i);
        paths[*v].push(i);
    }
    let mut q = BinaryHeap::new();
    q.push(Reverse((0, 0)));
    let mut min_dis: Vec<usize> = vec![usize::MAX; n];
    let mut parent: Vec<usize> = vec![0; n];
    min_dis[0] = 0;
    while let Some(Reverse((d, u))) = q.pop() {
        if min_dis[u] == d {
            for &i in &paths[u] {
                let (v, w, weight) = edges[i];
                let d = u ^ v ^ w;
                if min_dis[d] > min_dis[u] + weight {
                    parent[d] = i;
                    min_dis[d] = min_dis[u] + weight;
                    q.push(Reverse((min_dis[d], d)));
                }
            }
        }
    }
    let mut pick: Vec<usize> = (1..n).collect();
    pick.sort_unstable_by_key(|x| min_dis[*x]);
    println!("{}", k.min(n - 1));
    for i in 0..k.min(n - 1) {
        print!("{} ", parent[pick[i]] + 1);
    }
}