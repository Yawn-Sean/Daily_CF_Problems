
const LCA_DEPTH: usize = 31;
fn dfs(
    n: usize,
    dep: usize,
    fa: usize,
    father: &mut Vec<Vec<usize>>,
    depth: &mut Vec<usize>,
    childs: &Vec<Vec<usize>>,
) {
    depth[n] = dep;
    father[n][0] = fa;
    for j in 1..LCA_DEPTH {
        father[n][j] = father[father[n][j - 1]][j - 1];
    }
    for &child in childs[n].iter() {
        if child != fa {
            dfs(child, dep + 1, n, father, depth, childs);
        }
    }
}

fn lca(oa: usize, ob: usize, father: &Vec<Vec<usize>>, depth: &Vec<usize>) -> usize {
    let mut a = oa;
    let mut b = ob;
    if depth[a] > depth[b] {
        std::mem::swap(&mut a, &mut b);
    }
    let mut diff = depth[b] - depth[a];
    for j in (0..LCA_DEPTH).rev() {
        if diff & (1 << j) != 0 {
            b = father[b][j];
        }
    }
    if a == b {
        // println!("root of {oa} and {ob} is {a}, depth{}", depth[a]);
        return depth[a];
    }
    for j in (0..LCA_DEPTH).rev() {
        if father[a][j] != father[b][j] {
            a = father[a][j];
            b = father[b][j];
        }
    }
    a = father[a][0];
    // println!("rroot of {oa} and {ob} is {a}, depth{}", depth[a]);
    depth[a]
}

fn distance(oa: usize, ob: usize, father: &Vec<Vec<usize>>, depth: &Vec<usize>) -> usize {
    depth[oa] + depth[ob] - lca(oa, ob, father, depth) * 2
}

fn main() {
    input! {n: usize, q: usize}
    input! {x: [usize; n - 1]}
    input! {qs: [(usize, usize, usize); q]}
    let mut childs = vec![vec![]; n + 1];
    for (i, &x_i) in x.iter().enumerate() {
        childs[x_i].push(i + 2);
        childs[i + 2].push(x_i);
    }
    // println!("{childs:?}");
    let mut father = vec![vec![0; LCA_DEPTH]; n + 1];
    let mut depth = vec![0; n + 1];

    dfs(1, 1, 0, &mut father, &mut depth, &childs);
    for (a, b, c) in qs {
        let ab = distance(a, b, &father, &depth);
        let bc = distance(b, c, &father, &depth);
        let ac = distance(a, c, &father, &depth);
        let r = ab + bc + ac - 2 * ab.min(ac).min(bc);
        println!("{}", r / 2 + 1);
    }
}
