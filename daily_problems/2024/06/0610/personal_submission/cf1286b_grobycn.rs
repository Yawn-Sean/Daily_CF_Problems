// core logic only
// submission: https://codeforces.com/problemset/submission/1286/264996209
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut c = vec![0; n];
    let mut root = 0;
    for (i, (pi, ci)) in scanner.iter::<(usize, usize)>(n).enumerate() {
        if pi != 0 {
            adj[pi - 1].push(i);
        } else {
            root = i;
        }
        c[i] = ci;
    }

    fn dp(
        adj: &[Vec<usize>],
        cur: usize,
        c: &[usize],
        trees: &mut [Vec<usize>],
        ans: &mut [usize],
    ) -> bool {
        let mut tr = std::mem::replace(&mut trees[cur], vec![]);
        for &next in &adj[cur] {
            if !dp(adj, next, c, trees, ans) {
                return false;
            }
            for &node in &trees[next] {
                tr.push(node);
            }
        }
        if tr.len() < c[cur] {
            return false;
        }
        tr.sort_unstable_by_key(|&i| ans[i]);
        tr[..c[cur]]
            .iter()
            .chain([&cur])
            .chain(&tr[c[cur]..])
            .zip(1..)
            .for_each(|(&i, ord)| ans[i] = ord);
        tr.push(cur);
        trees[cur] = tr;
        true
    }

    let mut trees = vec![vec![]; n];
    let mut ans = vec![0; n];
    if !dp(&adj, root, &c, &mut trees, &mut ans) {
        return Err("NO");
    }
    Ok("YES"
        .cr()
        .then(Sep::<_, ' '>(ans.into_iter().map(|x| x + 1))))
}
