//! core logic only
//! submission: https://codeforces.com/contest/1089/submission/315158928
const MULTIPLE_TEST: bool = true;

use std::sync::OnceLock;
static RESULTS: OnceLock<Vec<Vec<Vec<Vec<(usize, usize)>>>>> = OnceLock::new();

fn solver(mut a: usize, mut b: usize) -> impl Printable {
    let results = RESULTS.get_or_init(|| {
        let mut results = vec![vec![vec![vec![(usize::MAX, usize::MAX); 201]; 201]; 4]; 4];
        results[0][0][0][0] = (0, 0);
        for set in 1..=5 {
            for win in 0..set.min(3) {
                let lose = set - 1 - win;
                if lose >= 3 {
                    continue;
                }
                for loser_score in 0..=188 {
                    let winner_score_at_least = if set == 5 { 15 } else { 25 };
                    let winner_score = if loser_score < winner_score_at_least - 1 {
                        winner_score_at_least
                    } else {
                        loser_score + 2
                    };
                    for score_a in 0..=200 - winner_score {
                        for score_b in 0..=200 - loser_score {
                            if results[win][lose][score_a][score_b] == (usize::MAX, usize::MAX) {
                                continue;
                            }
                            results[win + 1][lose][score_a + winner_score][score_b + loser_score] =
                                (winner_score, loser_score);
                        }
                    }
                    for score_a in 0..=200 - loser_score {
                        for score_b in 0..=200 - winner_score {
                            if results[win][lose][score_a][score_b] == (usize::MAX, usize::MAX) {
                                continue;
                            }
                            results[win][lose + 1][score_a + loser_score][score_b + winner_score] =
                                (loser_score, winner_score);
                        }
                    }
                }
            }
        }
        results
    });

    for (mut win, mut lose) in [(3, 0), (3, 1), (3, 2), (2, 3), (1, 3), (0, 3)] {
        if results[win][lose][a][b] != (usize::MAX, usize::MAX) {
            let match_result = Sep::<_, ':'>([win, lose]);
            let mut sets_result = Vec::with_capacity(win + lose);
            for _ in 0..sets_result.capacity() {
                let (score_a, score_b) = results[win][lose][a][b];
                sets_result.push(Sep::<_, ':'>([score_a, score_b]));
                if score_a > score_b {
                    win -= 1;
                } else {
                    lose -= 1;
                }
                a -= score_a;
                b -= score_b;
            }
            return Ok(match_result
                .cr()
                .then(Sep::<_, ' '>(sets_result.into_iter().rev())));
        }
    }
    Err("Impossible")
}
