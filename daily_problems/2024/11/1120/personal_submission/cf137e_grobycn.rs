//! core logic only
//! submission: https://codeforces.com/problemset/submission/137/292485191
const MULTIPLE_TEST: bool = false;
const VOWEL: u32 = (1 << (b'a' - b'a'))
    | (1 << (b'e' - b'a'))
    | (1 << (b'i' - b'a'))
    | (1 << (b'o' - b'a'))
    | (1 << (b'u' - b'a'));

fn solver(s: String) -> impl Printable {
    let (mut c, mut v) = (0, 0);
    let mut mn = 0;
    let mut mx = 0;
    for b in s.bytes() {
        if VOWEL & (1 << (b.to_ascii_lowercase() - b'a')) != 0 {
            v += 1;
        } else {
            c += 1;
        }
        let x = 2 * c - v;
        mn = mn.min(x);
        mx = mx.max(x);
    }
    let bias = -mn;
    let mut tr = Fenwick::new((mx + bias + 1) as usize);
    tr.update(bias as usize, 0);
    (c, v) = (0, 0);
    let (mut max_len, mut cnt) = (0, 0);
    for (b, i) in s.bytes().zip(1..) {
        if VOWEL & (1 << (b.to_ascii_lowercase() - b'a')) != 0 {
            v += 1;
        } else {
            c += 1;
        }
        let idx = (2 * c - v + bias) as usize;
        let left_most = tr.query(idx + 1);
        if left_most != usize::MAX {
            let len = i - left_most;
            if max_len < len {
                max_len = len;
                cnt = 1;
            } else if max_len == len {
                cnt += 1;
            }
        }
        tr.update(idx, i);
    }
    if max_len == 0 {
        return Err("No solution");
    }
    Ok((max_len, cnt))
}

struct Fenwick {
    arr: Vec<usize>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self {
            arr: vec![usize::MAX; n],
        }
    }
    fn query(&self, mut r: usize) -> usize {
        let mut ret = usize::MAX;
        while r > 0 {
            ret = ret.min(self.arr[r - 1]);
            r &= r - 1;
        }
        ret
    }
    fn update(&mut self, mut i: usize, v: usize) {
        while i < self.arr.len() {
            if self.arr[i] <= v {
                return;
            }
            self.arr[i] = v;
            i += (i + 1) & !i;
        }
    }
}
