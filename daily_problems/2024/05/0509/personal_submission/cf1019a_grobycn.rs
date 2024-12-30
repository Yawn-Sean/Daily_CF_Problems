// core logic only
// submission: https://codeforces.com/contest/1019/submission/260142823
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut votes: Vec<(usize, usize)> = scanner.iter(n).collect();
    votes.sort_unstable_by_key(|v| v.1);
    let mut bucket = vec![vec![]; m];
    for (i, &(p, _)) in votes.iter().enumerate() {
        bucket[p - 1].push(i);
    }
    let score = bucket[0].len();
    let max_score = bucket.iter().map(|b| b.len()).max().unwrap();
    if score > max_score {
        return 0;
    }
    let mut ans = usize::MAX;
    for final_score in score..=max_score + 1 {
        let mut cost = 0;
        let mut score = score;
        let mut revoted = vec![false; n];
        for b in &bucket[1..] {
            if b.len() >= final_score {
                b.iter().take(b.len() - final_score + 1).for_each(|&i| {
                    revoted[i] = true;
                    cost += votes[i].1;
                    score += 1;
                });
            }
        }
        if score < final_score {
            votes
                .iter()
                .zip(&revoted)
                .filter(|&(v, &r)| v.0 != 1 && !r)
                .take(final_score - score)
                .for_each(|(&c, _)| cost += c.1);
        }
        ans = ans.min(cost);
    }
    ans
}
