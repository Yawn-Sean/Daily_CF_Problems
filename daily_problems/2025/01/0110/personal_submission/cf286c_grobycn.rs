//! core logic only
//! submission: https://codeforces.com/problemset/submission/286/300389289
const MULTIPLE_TEST: bool = false;

fn solver(mut p: Vec<i32>, t: usize, scanner: &mut Scanner) -> impl Printable {
    let n = p.len();
    if n & 1 != 0 || t * 2 > n {
        return Err("NO");
    }
    for q in scanner.iter::<usize>(t) {
        p[q - 1] *= -1;
    }
    fn find_match(p: &mut [i32], undef: &mut Vec<usize>, neg_idx: usize) -> bool {
        let mut negs = vec![p[neg_idx]];
        while let Some(&x) = negs.last() {
            match undef.pop() {
                Some(j) if p[j] + x == 0 => {
                    negs.pop();
                }
                Some(j) => {
                    p[j] *= -1;
                    negs.push(p[j]);
                }
                _ => return false,
            }
        }
        true
    }

    let mut undef = vec![];
    for i in 0..n {
        if p[i] > 0 {
            undef.push(i);
        } else if !find_match(&mut p, &mut undef, i) {
            return Err("NO");
        }
    }
    while let Some(i) = undef.pop() {
        p[i] *= -1;
        if !find_match(&mut p, &mut undef, i) {
            return Err("NO");
        }
    }
    Ok("YES".cr().then(Sep::<_, ' '>(p)))
}
