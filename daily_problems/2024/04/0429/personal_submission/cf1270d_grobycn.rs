// core logic only
// submission: https://codeforces.com/contest/1270/submission/259006725
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ask = |xs: &[usize]| {
        ('?', Sep::<_, ' '>(xs.iter().copied()))
            .cr()
            .flush()
            .print_to(&mut std::io::stdout());
        <(usize, i32)>::from_scanner(scanner).1
    };

    let mut xs: Vec<_> = (1..=k).collect();
    let mut max = ask(&xs);
    let mut ans = 1;

    for i in 0..k {
        xs[i] = k + 1;
        let val = ask(&xs);
        if val > max {
            max = val;
            ans = 1;
        } else if val == max {
            ans += 1;
        }
        xs[i] = i + 1;
    }
    ('!', ans)
}
