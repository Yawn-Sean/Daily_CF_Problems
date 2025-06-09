//! core logic only
//! submission: https://codeforces.com/problemset/submission/234/317174184
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<u8>, b: Vec<u8>) -> impl Printable {
    let (n, m) = (a.len(), b.len());
    let states: Vec<_> = a.into_iter().chain(b).collect();

    fn merge(
        (start1, end1): (usize, usize),
        (start2, end2): (usize, usize),
        states: &[u8],
    ) -> (Vec<usize>, Vec<usize>) {
        let mut i = start1;
        let mut j = start2;
        let mut cards = vec![];
        while i < end1 {
            let mut e = i + 1;
            let st = states[i];
            while e < end1 && states[e] == st {
                e += 1;
            }
            cards.extend(i..e);
            i = e;
            if j < end2 && states[j] == st {
                let mut e = j + 1;
                while e < end2 && states[e] == st {
                    e += 1;
                }
                cards.extend(j..e);
                j = e;
            }
        }
        cards.extend(j..end2);

        let mut ops = vec![];
        let mut i = 0;
        while i < cards.len() {
            let mut e = i + 1;
            let st = states[cards[i]];
            while e < cards.len() && states[cards[e]] == st {
                e += 1;
            }
            if st == 1 {
                if i != 0 {
                    ops.push(i);
                }
                ops.push(e);
            }
            i = e;
        }

        (cards, ops)
    }

    let (mut cards, mut ops) = merge((0, n), (n, n + m), &states);
    let (cards2, ops2) = merge((n, n + m), (0, n), &states);
    if ops.len() > ops2.len() {
        cards = cards2;
        ops = ops2;
    }
    Sep::<_, ' '>(cards.into_iter().map(|x| x + 1))
        .cr()
        .then(ops.len())
        .cr()
        .then(Sep::<_, ' '>(ops))
}
