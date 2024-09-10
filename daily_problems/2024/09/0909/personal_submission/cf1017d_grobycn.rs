//! core logic only
//! submission: https://codeforces.com/problemset/submission/1017/280469913
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let w: Vec<usize> = scanner.iter(n).collect();
    let mut wu = vec![0; 1 << n];
    for mask in 0..1 << n {
        let mut sum = 0;
        for (i, &x) in w.iter().rev().enumerate() {
            if mask & (1 << i) != 0 {
                sum += x;
            }
        }
        wu[mask] = sum;
    }
    let mut count = vec![0; 1 <<  n];
    for s in scanner.iter::<String>(m) {
        let mask = usize::from_str_radix(&s, 2).unwrap();
        count[mask] += 1;
    }
    let mut preprocess = vec![vec![0; 101]; 1 << n];
    for mask_t in 0..1 << n {
        for (mask_s, &cnt) in count.iter().enumerate() {
            let mask = mask_t ^ mask_s ^ ((1 << n) - 1);
            if wu[mask] <= 100 {
                preprocess[mask_t][wu[mask]] += cnt;
            }
        }
    }
    preprocess.iter_mut().for_each(|xs| {
        for i in 1..=100 {
            xs[i] += xs[i - 1];
        }
    });

    let ans: Vec<_> = scanner.iter::<(String, usize)>(q).map(|(s, k)| {
        let mask = usize::from_str_radix(&s, 2).unwrap();
        preprocess[mask][k]
    }).collect();
    Sep::<_, '\n'>(ans)
}
