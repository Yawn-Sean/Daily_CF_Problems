//! core logic only
//! submission: https://codeforces.com/problemset/submission/627/304988608
const MULTIPLE_TEST: bool = false;

fn solver(d: usize, n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut stations: Vec<(usize, usize)> = scanner.iter(m).collect();
    stations.sort_unstable();
    let mut stk: Vec<usize> = vec![];
    let mut next_cheaper_station = vec![usize::MAX; m];
    for (i, &(_, p)) in stations.iter().enumerate() {
        while let Some(&j) = stk.last() {
            if stations[j].1 > p {
                next_cheaper_station[j] = i;
                stk.pop();
            } else {
                break;
            }
        }
        stk.push(i);
    }

    let mut ans = 0;
    let mut remaining_gas = n;
    let mut pos = 0;
    for (i, &(x, p)) in stations.iter().enumerate() {
        let dist = x - pos;
        if remaining_gas < dist {
            return Err(-1);
        }
        remaining_gas -= dist;
        let r = next_cheaper_station[i];
        let target = if r == usize::MAX { d } else { stations[r].0 };
        let bought = n.min(target - x).saturating_sub(remaining_gas);
        ans += bought * p;
        remaining_gas += bought;
        pos = x;
    }
    if remaining_gas < d - pos {
        return Err(-1);
    }
    Ok(ans)
}
