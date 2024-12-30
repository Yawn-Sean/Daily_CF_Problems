// core logic only
// submission: https://codeforces.com/contest/1219/submission/261213499
const MULTIPLE_TEST: bool = false;

fn find_sum_of_nlargest(xs: impl Iterator<Item = usize>, n: usize) -> usize {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;
    let mut hp = BinaryHeap::new();
    for x in xs {
        hp.push(Reverse(x));
        if hp.len() > n {
            hp.pop();
        }
    }
    hp.into_iter().map(|Reverse(x)| x).sum()
}

fn solver(Mat(mat): Mat<usize>) -> impl Printable {
    let (n, m) = (mat.len(), mat[0].len());
    if n <= 4 || m <= 4 {
        return mat.iter().map(|row| row.iter()).flatten().sum::<usize>();
    }
    let rsum: Vec<_> = mat.iter().map(|row| row.iter().sum::<usize>()).collect();
    let csum: Vec<_> = (0..m)
        .map(|c| mat.iter().map(|row| row[c]).sum::<usize>())
        .collect();

    let mut ans = find_sum_of_nlargest(rsum.iter().copied(), 4);
    ans = ans.max(find_sum_of_nlargest(csum.iter().copied(), 4));

    for (row, &sum) in mat.iter().zip(&rsum) {
        let csum = csum.iter().zip(row).map(|(&sum, &x)| sum - x);
        ans = ans.max(find_sum_of_nlargest(csum, 3) + sum);
    }
    for (c, &sum) in csum.iter().enumerate() {
        let rsum = rsum.iter().zip(&mat).map(|(&sum, row)| sum - row[c]);
        ans = ans.max(find_sum_of_nlargest(rsum, 3) + sum);
    }
    if n < m {
        for (r1, (&sum1, row1)) in rsum.iter().zip(&mat).enumerate() {
            for (&sum2, row2) in rsum[..r1].iter().zip(&mat) {
                let csum = csum
                    .iter()
                    .zip(row1)
                    .zip(row2)
                    .map(|((&sum, &x), &y)| sum - x - y);
                ans = ans.max(find_sum_of_nlargest(csum, 2) + sum1 + sum2);
            }
        }
    } else {
        for (c1, &sum1) in csum.iter().enumerate() {
            for (c2, &sum2) in csum[..c1].iter().enumerate() {
                let rsum = rsum
                    .iter()
                    .zip(&mat)
                    .map(|(&sum, row)| sum - row[c1] - row[c2]);
                ans = ans.max(find_sum_of_nlargest(rsum, 2) + sum1 + sum2);
            }
        }
    }
    ans
}
