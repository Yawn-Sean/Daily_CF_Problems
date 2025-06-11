//! core logic only
//! submission: https://codeforces.com/problemset/submission/212/315145830
const MULTIPLE_TEST: bool = false;

fn solver(state: String) -> impl Printable {
    let mut state = state.into_bytes();
    state.push(state[0]);
    let (mut aa, mut ab) = (1usize, 0);
    let (mut ba, mut bb) = (0, 1);
    for w in state.windows(2) {
        match (w[0], w[1]) {
            (b'A', b'A') => {
                (aa, ab) = (aa + ab, 0);
                (ba, bb) = (ba + bb, 0);
            }
            (b'A', b'B') => {
                (aa, ab) = (aa + ab, ab);
                (ba, bb) = (ba + bb, bb);
            }
            (b'B', b'A') => {
                (aa, ab) = (ab, aa);
                (ba, bb) = (bb, ba);
            }
            _ => {
                (aa, ab) = (ab, ab);
                (ba, bb) = (bb, bb);
            }
        }
    }
    aa + bb
}
