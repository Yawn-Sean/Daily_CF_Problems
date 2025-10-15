//! core logic only
//! submission: https://codeforces.com/problemset/submission/534/301607020
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let rows: Vec<usize> = scanner.iter(n).collect();
    let cols: Vec<usize> = scanner.iter(m).collect();

    let left = m / 2;
    let right = m - left;
    let border_state_count = 1 << n;
    let mut vertline_masks = vec![vec![]; n + 1];
    for msk in 0..border_state_count {
        let mut cnt = 0;
        let mut isblack = false;
        for i in 0..n {
            if msk & (1 << i) != 0 {
                if !isblack {
                    cnt += 1;
                    isblack = true;
                }
            } else {
                isblack = false;
            }
        }
        vertline_masks[cnt].push(msk);
    }

    let horizline_max_black_block = (right + 1) / 2;
    let rows_state_count = (horizline_max_black_block + 1).pow(n as u32);
    let mut dpl = vec![vec![vec![usize::MAX; rows_state_count]; border_state_count]; left + 1];
    dpl[0][0][0] = usize::MAX - 1;
    for (i, &c) in cols[..left].iter().enumerate() {
        for old_border in 0..border_state_count {
            for old_rows_state in 0..rows_state_count {
                if dpl[i][old_border][old_rows_state] == usize::MAX {
                    continue;
                }
                for &new_border in vertline_masks[c].iter() {
                    let new_black_blocks = new_border & (new_border ^ old_border);
                    let mut new_rows_state = old_rows_state;
                    let mut pow = 1;
                    for r in 0..n {
                        if new_black_blocks & (1 << r) != 0 {
                            new_rows_state += pow;
                        }
                        pow = pow * (horizline_max_black_block + 1);
                    }
                    dpl[i + 1][new_border][new_rows_state] =
                        old_rows_state * border_state_count + old_border;
                }
            }
        }
    }

    let mut dpr = vec![vec![vec![usize::MAX; rows_state_count]; border_state_count]; right + 1];
    dpr[0][0][0] = usize::MAX - 1;
    for (i, &c) in cols[left..].iter().rev().enumerate() {
        for old_border in 0..border_state_count {
            for old_rows_state in 0..rows_state_count {
                if dpr[i][old_border][old_rows_state] == usize::MAX {
                    continue;
                }
                for &new_border in vertline_masks[c].iter() {
                    let new_black_blocks = new_border & (new_border ^ old_border);
                    let mut new_rows_state = old_rows_state;
                    let mut pow = 1;
                    for r in 0..n {
                        if new_black_blocks & (1 << r) != 0 {
                            new_rows_state += pow;
                        }
                        pow = pow * (horizline_max_black_block + 1);
                    }
                    dpr[i + 1][new_border][new_rows_state] =
                        old_rows_state * border_state_count + old_border;
                }
            }
        }
    }

    for border_l in 0..border_state_count {
        for rows_state_l in 0..rows_state_count {
            if dpl[left][border_l][rows_state_l] == usize::MAX {
                continue;
            }
            for border_r in 0..border_state_count {
                let common = border_l & border_r;
                let mut tmp = rows_state_l;
                let mut rows_state_r = 0;
                let mut pow = 1;
                for (i, &c) in rows.iter().enumerate() {
                    let lcnt = tmp % (horizline_max_black_block + 1);
                    let (rcnt, overflow) = (c + ((common >> i) & 1)).overflowing_sub(lcnt);
                    if overflow || rcnt > horizline_max_black_block {
                        rows_state_r = usize::MAX;
                        break;
                    }
                    tmp /= horizline_max_black_block + 1;
                    rows_state_r += rcnt * pow;
                    pow = pow * (horizline_max_black_block + 1);
                }
                if rows_state_r < rows_state_count
                    && dpr[right][border_r][rows_state_r] != usize::MAX
                {
                    let mut ans = vec![vec![b'.'; m]; n];
                    let mut border = border_l;
                    let mut rows_state = rows_state_l;
                    for c in (0..left).rev() {
                        for r in 0..n {
                            if border & (1 << r) != 0 {
                                ans[r][c] = b'*';
                            }
                        }
                        let state = dpl[c + 1][border][rows_state];
                        border = state % border_state_count;
                        rows_state = state / border_state_count;
                    }

                    border = border_r;
                    rows_state = rows_state_r;
                    for c in left..m {
                        for r in 0..n {
                            if border & (1 << r) != 0 {
                                ans[r][c] = b'*';
                            }
                        }
                        let state = dpr[m - c][border][rows_state];
                        border = state % border_state_count;
                        rows_state = state / border_state_count;
                    }
                    return Sep::<_, '\n'>(
                        ans.into_iter()
                            .map(|row| unsafe { String::from_utf8_unchecked(row) }),
                    );
                }
            }
        }
    }
    unreachable!()
}
