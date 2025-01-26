//! core logic only
//! submission: https://codeforces.com/problemset/submission/416/302835844
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i64>) -> impl Printable {
    let n = a.len();
    let mut ans = 0;
    let mut i = 0;
    while i < n {
        ans += 1;
        let mut pos = Vec::with_capacity(2);
        let mut e = i;
        while e < n && pos.len() < 2 {
            if a[e] > 0 {
                pos.push(e);
            }
            e += 1;
        }
        if let [first, second] = pos[..] {
            let dy = a[second] - a[first];
            let dx = (second - first) as i64;
            if dy % dx == 0 {
                let d = dy / dx;
                let l = a[first] - ((first - i) as i64) * d;
                if l > 0 {
                    let mut next = a[second] + d;
                    while e < n && next > 0 && (a[e] == -1 || a[e] == next) {
                        next += d;
                        e += 1;
                    }
                    i = e;
                    continue;
                }
            }
            i = second;
        } else {
            i = e;
        }
    }
    ans
}
