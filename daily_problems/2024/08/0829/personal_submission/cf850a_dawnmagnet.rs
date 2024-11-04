fn main() {
    input! { n: usize }
    input! { p: [[i64; 5]; n] }

    if n >= 12 {
        println!("0");
        return;
    }
    let mut ans: BTreeSet<usize> = BTreeSet::new();
    for i in 0..n {
        ans.insert(i);
    }

    for i in 0..n {
        for j in 0..n {
            for k in 0..n {
                if i != j && j != k && k != i {
                    // check whether the angle ab with ac is acute
                    let mut cur = 0;
                    for s in 0..5 {
                        cur += (p[i][s] - p[j][s]) * (p[i][s] - p[k][s]);
                    }

                    if cur > 0 {
                        ans.remove(&i);
                        break;
                    }
                }
            }

            if !ans.contains(&i) {
                break;
            }
        }
    }
    println!("{}", ans.len());
    for item in ans {
        println!("{}", item + 1);
    }
}