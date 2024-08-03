// core logic only
// submission: https://codeforces.com/problemset/submission/1010/257192997
const MULTIPLE_TEST: bool = false;

#[derive(Clone, Copy)]
enum Gate {
    And(usize, usize),
    Or(usize, usize),
    Xor(usize, usize),
    Not(usize),
    In(u8),
}

impl FromScanner for Gate {
    fn from_scanner(scanner: &mut Scanner) -> Self {
        match String::from_scanner(scanner).as_ref() {
            "AND" => Gate::And(
                usize::from_scanner(scanner) - 1,
                usize::from_scanner(scanner) - 1,
            ),
            "OR" => Gate::Or(
                usize::from_scanner(scanner) - 1,
                usize::from_scanner(scanner) - 1,
            ),
            "XOR" => Gate::Xor(
                usize::from_scanner(scanner) - 1,
                usize::from_scanner(scanner) - 1,
            ),
            "NOT" => Gate::Not(usize::from_scanner(scanner) - 1),
            "IN" => Gate::In(u8::from_scanner(scanner)),
            _ => unreachable!(),
        }
    }
}

fn solver(circuit: Vec<Gate>) -> impl Printable {
    fn dfs(circuit: &[Gate], cur: usize, output: &mut [u8]) -> u8 {
        output[cur] = match circuit[cur] {
            Gate::And(l, r) => dfs(circuit, l, output) & dfs(circuit, r, output),
            Gate::Or(l, r) => dfs(circuit, l, output) | dfs(circuit, r, output),
            Gate::Xor(l, r) => dfs(circuit, l, output) ^ dfs(circuit, r, output),
            Gate::Not(i) => dfs(circuit, i, output) ^ 1,
            Gate::In(input) => input,
        };
        output[cur]
    }

    let n = circuit.len();
    let mut output = vec![0; n];
    dfs(&circuit, 0, &mut output);
    // ans[i] is what we got when we change the output of gate i
    let mut ans = vec![output[0]; n];

    fn dfs2(circuit: &[Gate], cur: usize, output: &[u8], ans: &mut [u8]) {
        match circuit[cur] {
            Gate::And(l, r) => match (output[l], output[r]) {
                (0, 1) => dfs2(circuit, l, output, ans),
                (1, 0) => dfs2(circuit, r, output, ans),
                (1, 1) => {
                    dfs2(circuit, l, output, ans);
                    dfs2(circuit, r, output, ans);
                }
                _ => {}
            },
            Gate::Or(l, r) => match (output[l], output[r]) {
                (0, 1) => dfs2(circuit, r, output, ans),
                (1, 0) => dfs2(circuit, l, output, ans),
                (0, 0) => {
                    dfs2(circuit, l, output, ans);
                    dfs2(circuit, r, output, ans);
                }
                _ => {}
            },
            Gate::Xor(l, r) => {
                dfs2(circuit, l, output, ans);
                dfs2(circuit, r, output, ans);
            }
            Gate::Not(i) => dfs2(circuit, i, output, ans),
            Gate::In(input) => {
                ans[cur] ^= 1;
            }
        }
    }

    dfs2(&circuit, 0, &output, &mut ans);
    let ans: Vec<_> = (0..n)
        .filter_map(|i| {
            if matches!(circuit[i], Gate::In(_)) {
                Some(ans[i] + b'0')
            } else {
                None
            }
        })
        .collect();
    String::from_utf8(ans).unwrap()
}
