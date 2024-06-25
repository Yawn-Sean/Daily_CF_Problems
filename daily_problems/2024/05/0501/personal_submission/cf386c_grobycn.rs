// core logic only
// submission: https://codeforces.com/contest/386/submission/258981630
const MULTIPLE_TEST: bool = false;
use std::collections::HashMap;

fn solver(s: String) -> impl Printable {
    let s = s.into_bytes();
    let ds = s
        .iter()
        .fold(0u32, |acc, &b| acc | (1 << (b - b'a')))
        .count_ones() as usize;
    let t = (1..=ds).map(move |k| {
        let mut ans = 0;
        let (mut l1, mut l2) = (0, 0);
        let (mut set1, mut set2) = (HashMap::new(), HashMap::new());
        for &b in s.iter() {
            set1.add1(b);
            while set1.len() >= k {
                set1.remove1(&s[l1]);
                l1 += 1;
            }
            set2.add1(b);
            while set2.len() > k {
                set2.remove1(&s[l2]);
                l2 += 1;
            }
            if set1.len() == k - 1 && set2.len() == k {
                ans += l1 - l2;
            }
        }
        ans
    });
    ds.cr().then(Sep::<_, '\n'>(t))
}

trait MultiSet<T> {
    fn add1(&mut self, x: T);
    fn remove1(&mut self, x: &T);
}

impl<T: Eq + std::hash::Hash> MultiSet<T> for HashMap<T, usize> {
    fn add1(&mut self, x: T) {
        *self.entry(x).or_insert(0) += 1;
    }
    fn remove1(&mut self, x: &T) {
        match self.get_mut(x) {
            Some(cnt) if *cnt > 1 => *cnt -= 1,
            _ => {
                self.remove(x);
            }
        }
    }
}
