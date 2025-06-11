//! core logic only
//! submission: https://codeforces.com/problemset/submission/263/307012988
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;
    let mut adj = vec![HashSet::new(); n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(2 * n) {
        (a, b) = (a - 1, b - 1);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    if adj.iter().any(|nb| nb.len() != 4) {
        return Err(-1);
    }

    let fst = 0;
    for &snd in adj[fst].iter() {
        for &trd in adj[snd].iter() {
            if trd == fst || !adj[fst].contains(&trd) {
                continue;
            }
            let mut vis = vec![false; n];
            let mut ans = Vec::with_capacity(n);
            let (mut fst, mut snd, mut trd) = (fst, snd, trd);
            vis[fst] = true;
            vis[snd] = true;
            vis[trd] = true;
            ans.extend([fst + 1, snd + 1, trd + 1]);
            while ans.len() < n {
                match adj[snd]
                    .intersection(&adj[trd])
                    .filter(|&&x| !vis[x])
                    .next()
                {
                    Some(&next) => {
                        vis[next] = true;
                        ans.push(next + 1);
                        (fst, snd, trd) = (snd, trd, next);
                    }
                    _ => break,
                }
            }
            if ans.len() == n {
                return Ok(Sep::<_, ' '>(ans));
            }
        }
    }
    Err(-1)
}
