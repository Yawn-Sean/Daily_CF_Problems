// core logic only
// submission: https://codeforces.com/problemset/submission/749/257987062
const MULTIPLE_TEST: bool = false;

fn solver(auctions: Vec<(usize, usize)>, questions: Vec<Vec<usize>>) -> impl Printable {
    let n = auctions.len();
    let mut group = vec![vec![]; n];
    for (&(a, b), i) in auctions.iter().zip(1..) {
        group[a - 1].push(i);
    }
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| *group[i].last().unwrap_or(&0));

    let mut absent = vec![false; n];
    let ans: Vec<_> = questions
        .into_iter()
        .map(|idxs| {
            for &i in &idxs {
                absent[i - 1] = true;
            }
            let gs: Vec<_> = indices
                .iter()
                .rev()
                .filter_map(|&i| if absent[i] { None } else { Some(&group[i]) })
                .take(2)
                .filter(|g| !g.is_empty())
                .collect();

            let ans = match gs.len() {
                2 => {
                    let max = *gs[1].last().unwrap();
                    let i = gs[0].partition_point(|&i| i < max);
                    auctions[gs[0][i] - 1]
                }
                1 => auctions[gs[0][0] - 1],
                _ => (0, 0),
            };

            for i in idxs {
                absent[i - 1] = false;
            }
            ans
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
