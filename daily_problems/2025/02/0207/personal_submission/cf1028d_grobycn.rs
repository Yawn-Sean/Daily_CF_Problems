//! core logic only
//! submission: https://codeforces.com/problemset/submission/1028/304854273
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BTreeSet;
    let mut offers = BTreeSet::new();
    let (mut max_buy_price, mut min_sell_price) = (0, usize::MAX);
    let mut cnt = 0;
    for (action, price) in scanner.iter::<(String, usize)>(n) {
        if action == "ADD" {
            offers.insert(price);
        } else {
            if price < max_buy_price || price > min_sell_price {
                return 0;
            }
            if max_buy_price < price && price < min_sell_price {
                cnt += 1;
            }
            offers.remove(&price);
            max_buy_price = *offers.range(..price).next_back().unwrap_or(&0);
            min_sell_price = *offers.range(price..).next().unwrap_or(&usize::MAX);
        }
    }
    let mut ans = offers.range(max_buy_price + 1..min_sell_price).count() + 1;
    ans *= powermod(2, cnt, MOD);
    ans % MOD
}

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x != 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        x >>= 1;
        e = (e * e) % m;
    }
    ret
}
