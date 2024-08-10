use std::vec;

fn main() {
    input! { n: usize, m: usize, k: usize }
    input! { v: [[u8; m]; n] }

    // println!("{:?}", v);
    let mut res = 1000000;

    if m > k {
        let mut bin: Vec<i128> = vec![0; m];
        for i in 0..n {
            for j in 0..m {
                if v[i][j] == 1 {
                    bin[j] ^= 1 << i;
                }
            }
        }
        for i in 0..m {
            let mut cnt = 0;
            for j in 0..m {
                let t = (bin[j] ^ bin[i]).count_ones();
                cnt += t.min(n as u32 - t);
            }
            res = res.min(cnt);
        }
        res
    } else {
        let mut bin: Vec<i128> = vec![0; n];
        for i in 0..n {
            for j in 0..m {
                if v[i][j] == 1 {
                    bin[i] ^= 1 << j;
                }
            }
        }
        let mut res = 1000000;
        for tr in 0..(1 << m) {
            let mut cnt = 0;
            for i in 0..n {
                let t = (bin[i] ^ tr).count_ones();
                cnt += t.min(m as u32 - t);
            }
            res = res.min(cnt);
        }
        res
    }
    if res <= k as u32 {
        println!("{}", res);
    } else {
        println!("-1");
    }
}
