//! core logic only
//! submission: https://codeforces.com/problemset/submission/631/318059135
const MULTIPLE_TEST: bool = false;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct Block {
    ch: u8,
    len: usize,
}

impl Block {
    fn contains(&self, blk: Self) -> bool {
        self.ch == blk.ch && self.len >= blk.len
    }
    fn count_contains(&self, blk: Self) -> usize {
        if self.ch == blk.ch {
            (self.len + 1).saturating_sub(blk.len)
        } else {
            0
        }
    }
}

impl FromStr for Block {
    type Err = ();
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let n = s.len();
        if n <= 2 {
            return Err(());
        }
        let ch = s.as_bytes()[n - 1];
        let len = s[..n - 2].parse().map_err(|_| ())?;
        Ok(Self { ch, len })
    }
}

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    fn read_compress_str(scanner: &mut Scanner, block_cnt: usize) -> Vec<Block> {
        let mut ret: Vec<Block> = (0..block_cnt).map(|_| scanner.next()).collect();
        ret.dedup_by(|r, l| {
            if r.ch == l.ch {
                l.len += r.len;
                true
            } else {
                false
            }
        });
        ret
    }

    let t = read_compress_str(scanner, n);
    let mut s = read_compress_str(scanner, m);
    let (n, m) = (t.len(), s.len());
    if n < m {
        return 0;
    }
    match m {
        1 => t.iter().map(|blk| blk.count_contains(s[0])).sum(),
        2 => t
            .windows(2)
            .filter(|w| w[0].contains(s[0]) && w[1].contains(s[1]))
            .count(),
        _ => {
            let mut ans = 0;
            let first_block = s[0];
            let last_block = std::mem::replace(&mut s[m - 1], Block { ch: 0, len: 0 });
            s.extend(t);
            // concat = s[1..m - 1] + special block + t
            let concat = &s[1..];
            let mut lps = vec![0; concat.len()];
            let mut l = 0;
            for i in 1..concat.len() {
                while concat[i] != concat[l] && l > 0 {
                    l = lps[l - 1];
                }
                if concat[i] == concat[l] {
                    l += 1;
                    lps[i] = l;
                }
            }

            for (w, matched) in concat[m - 1..].windows(m).zip(lps[m..].windows(m - 2)) {
                if matched[m - 3] == m - 2
                    && w[0].contains(first_block)
                    && w[m - 1].contains(last_block)
                {
                    ans += 1;
                }
            }
            ans
        }
    }
}
