//! core logic only
//! submission: https://codeforces.com/problemset/submission/487/287219604
const MULTIPLE_TEST: bool = false;

fn solver(
    hpy: usize,
    atky: usize,
    defy: usize,
    hpm: usize,
    atkm: usize,
    defm: usize,
    h: usize,
    a: usize,
    d: usize,
) -> impl Printable {
    let mut ans = usize::MAX;
    for def in defy.min(atkm)..=atkm {
        let cost_for_def = def.saturating_sub(defy) * d;
        for atk in atky.max(defm + 1).. {
            let cost_for_atk = atk.saturating_sub(atky) * a;
            let round = hpm.div_ceil(atk - defm);
            let hp = (atkm - def) * round + 1;
            let cost_for_hp = hp.saturating_sub(hpy) * h;
            ans = ans.min(cost_for_def + cost_for_atk + cost_for_hp);
            if round == 1 {
                break;
            }
        }
    }
    ans
}
