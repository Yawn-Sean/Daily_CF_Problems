//! core logic obly
//! submission: https://codeforces.com/problemset/submission/178/286396138
const MULTIPLE_TEST: bool = false;

fn solver(h: usize, m: usize, n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::{BTreeSet, HashMap};

    let mut sets = vec![];
    let mut which_set = vec![usize::MAX; h];
    let mut vis = vec![false; h];
    let mut indices = vec![usize::MAX; h];
    let mut set_sizes = vec![];
    for mut i in 0..h {
        if vis[i] {
            continue;
        }
        let mut set = BTreeSet::new();
        let set_idx = sets.len();
        let mut idx = 0;
        while !vis[i] {
            vis[i] = true;
            indices[i] = idx;
            set.insert(idx);
            idx += 1;
            which_set[i] = set_idx;
            i = (i + m) % h;
        }
        set_sizes.push(set.len());
        sets.push(set);
    }

    let mut slots = HashMap::new();
    let mut ans = 0;
    for _ in 0..n {
        let op = String::from_scanner(scanner);
        let id = usize::from_scanner(scanner);
        if op == "+" {
            let hash = usize::from_scanner(scanner);
            let idx = indices[hash];
            let set_idx = which_set[hash];
            let set = &mut sets[set_idx];
            let set_sz = set_sizes[set_idx];
            if let Some(slot) = set
                .range(idx..)
                .next()
                .or_else(|| set.iter().next())
                .copied()
            {
                set.remove(&slot);
                ans += if slot >= idx {
                    slot - idx
                } else {
                    set_sz + slot - idx
                };
                slots.insert(id, (slot, set_idx));
            }
        } else {
            if let Some((slot, set_idx)) = slots.remove(&id) {
                sets[set_idx].insert(slot);
            }
        }
    }
    ans
}
