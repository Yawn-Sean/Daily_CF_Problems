//! core logic only
//! submission: https://codeforces.com/problemset/submission/868/289445699
const MULTIPLE_TEST: bool = false;

fn solver(s: Vec<String>, m: usize, scanner: &mut Scanner) -> impl Printable {
    let n = s.len();
    let mut pres = Vec::with_capacity(n + m);
    let mut sufs = Vec::with_capacity(n + m);
    let mut vis = Vec::with_capacity(n + m);

    for si in s.iter() {
        pres.push(si.bytes().take(9).collect::<Vec<_>>());
        sufs.push(si.bytes().rev().take(9).collect::<Vec<_>>());
        let mut v = vec![0; 1 << 10];
        for start in 0..si.len() {
            let mut num = 0;
            for (l, b) in si[start..].bytes().take(10).enumerate() {
                num = (num << 1) | ((b - b'0') as usize);
                v[num] |= 1 << l;
            }
        }
        vis.push(v);
    }

    let mut ans = Vec::with_capacity(m);
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(m) {
        (a, b) = (a - 1, b - 1);
        let mut v = vec![0; 1 << 10];
        for num in 0..1 << 10 {
            v[num] = vis[a][num] | vis[b][num];
        }
        let mut num = 0;
        for (mut i, &c) in sufs[a].iter().enumerate() {
            num |= ((c - b'0') as usize) << i;
            let mut num = num;
            for &c in pres[b].iter() {
                i += 1;
                if i >= 10 {
                    break;
                }
                num = (num << 1) | ((c - b'0') as usize);
                v[num] |= 1 << i;
            }
        }
        let k = (0..10)
            .find(|&i| {
                v.iter()
                    .take(1 << (i + 1))
                    .any(|&mask| mask & (1 << i) == 0)
            })
            .unwrap_or(10);
        ans.push(k);
        vis.push(v);
        let pre = pres[a].iter().chain(&pres[b]).take(9).copied().collect();
        let suf = sufs[b].iter().chain(&sufs[a]).take(9).copied().collect();
        pres.push(pre);
        sufs.push(suf);
    }
    Sep::<_, '\n'>(ans)
}
