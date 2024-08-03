// core logic only
// submission: https://codeforces.com/contest/870/submission/254835697
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ask = |i: usize, j: usize| {
        println!("? {i} {j}");
        usize::from_scanner(scanner)
    };

    let mut xorpib0: Vec<_> = (0..n).map(|i| ask(i, 0)).collect();
    let mut cnt = 0;
    if n % 2 == 0 {
        let mut xorbip0 = Vec::with_capacity(n);
        xorbip0.push(xorpib0[0]);
        xorbip0.extend((1..n).map(|i| ask(0, i)));
        let mut valid_b0 = 0;
        let mut visp = vec![usize::MAX; n];
        let mut visb = vec![usize::MAX; n];
        'outter: for b0 in 0..n {
            let p0 = b0 ^ xorpib0[0];
            for &x in xorpib0.iter() {
                let pi = b0 ^ x;
                if pi >= n || visp[pi] == b0 {
                    continue 'outter;
                }
                visp[pi] = b0;
            }
            for (i, &x) in xorbip0.iter().enumerate() {
                let bi = p0 ^ x;
                if bi >= n || visb[bi] == b0 {
                    continue 'outter;
                }
                let pbi = xorpib0[bi] ^ b0;
                if pbi != i {
                    continue 'outter;
                }
                visb[bi] = b0;
            }
            cnt += 1;
            valid_b0 = b0;
        }
        xorpib0.iter_mut().for_each(|x| *x ^= valid_b0);
    } else {
        cnt = 1;
        let b0 = xorpib0
            .iter()
            .enumerate()
            .fold(0, |acc, (i, &x)| acc ^ i ^ x);
        xorpib0.iter_mut().for_each(|x| *x ^= b0);
    }

    '!'.cr().then(cnt).cr().then(Sep::<_, ' '>(xorpib0))
}
