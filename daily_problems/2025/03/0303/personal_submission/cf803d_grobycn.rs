//! core logic only
//! submission: https://codeforces.com/problemset/submission/803/308803149
const MULTIPLE_TEST: bool = false;

fn solver(k: usize, scanner: &mut Scanner) -> impl Printable {
    let text = scanner.next_whole_line();
    let text = text.trim();
    let word_cnt = text.split([' ', '-']).count();
    let check = |line_width: usize| {
        let mut line_cnt = 1;
        let mut width = 0;
        for (i, word) in text.split([' ', '-']).enumerate() {
            let w = word.len() + usize::from(i + 1 != word_cnt);
            if width + w > line_width {
                line_cnt += 1;
                if line_cnt > k || w > line_width {
                    return false;
                }
                width = w;
            } else {
                width += w;
            }
        }
        true
    };

    let (mut lo, mut hi) = (0, text.len());
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    hi
}
