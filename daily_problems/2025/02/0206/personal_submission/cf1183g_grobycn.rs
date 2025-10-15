//! core logic only
//! submission: https://codeforces.com/problemset/submission/1183/307414853
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BinaryHeap;
    let mut cnta = vec![0; n];
    let mut sumf = vec![0; n];

    for (a, f) in scanner.iter::<(usize, usize)>(n) {
        cnta[a - 1] += 1;
        sumf[a - 1] += f;
    }

    let mut types: Vec<_> = (0..n).filter(|&t| cnta[t] != 0).collect();
    types.sort_unstable_by_key(|&t| cnta[t]);
    let mut iter = types.iter().rev().peekable();
    let mut hp = BinaryHeap::new();
    let mut total_candies = 0;
    let mut total_f = 0;
    let mut last = usize::MAX;
    for &t in types.iter().rev() {
        let num = cnta[t].min(last - 1);
        if num == 0 {
            break;
        }
        while let Some(&t) = iter.next_if(|&&t| cnta[t] >= num) {
            hp.push(sumf[t]);
        }
        total_f += hp.pop().unwrap().min(num);
        total_candies += num;
        last = num;
    }

    (total_candies, total_f)
}
