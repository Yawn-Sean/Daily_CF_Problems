fn main() {
    input! { n: usize }
    let mut cards = vec![];
    for i in 0..n {
        input! { j: usize, card: [(usize, i64); j] }
        cards.push(card);
    }
    // eprintln!("{:?}", cards);

    let mut dp = [-1i64; 10];
    dp[0] = 0;
    for turn in cards {
        let mut ways = vec![];
        if turn.len() > 1 {
            let mut costs = vec![vec![]; 4];
            for (co, va) in turn {
                costs[co].push(va);
            }
            for i in 1..=3 {
                costs[i].sort_unstable();
                costs[i].reverse();
            }
            if !costs[1].is_empty() {
                ways.push((1, costs[1][0], costs[1][0]));
                if costs[1].len() >= 2 {
                    ways.push((2, costs[1][0] + costs[1][1], costs[1][0]));
                    if costs[1].len() >= 3 {
                        ways.push((3, costs[1][0] + costs[1][1] + costs[1][2], costs[1][0]));
                    }
                }
            }
            if !costs[2].is_empty() {
                ways.push((1, costs[2][0], costs[2][0]));
                if !costs[2].is_empty() && !costs[1].is_empty() {
                    ways.push((2, costs[1][0] + costs[2][0], costs[1][0].max(costs[2][0])))
                }
            }
            if !costs[3].is_empty() {
                ways.push((1, costs[3][0], costs[3][0]));
            }
        } else {
            ways.push((1, turn[0].1, turn[0].1));
        }
        ways.push((0, 0, 0));
        // eprintln!("{:?}", ways);
        let mut dp_nxt = [-1; 10];
        for (use_cards, value, value_bounced) in ways {
            for i in 0..10 {
                if dp[i] != -1 {
                    if i + use_cards >= 10 {
                        dp_nxt[i + use_cards - 10] =
                            dp_nxt[i + use_cards - 10].max(dp[i] + value_bounced + value);
                    } else {
                        dp_nxt[i + use_cards] = dp_nxt[i + use_cards].max(dp[i] + value);
                    }
                }
            }
        }
        dp = dp_nxt;
    }
    println!("{}", dp.iter().max().unwrap())
}