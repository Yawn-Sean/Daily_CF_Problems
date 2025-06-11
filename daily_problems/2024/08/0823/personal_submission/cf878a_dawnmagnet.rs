fn getbit(x: usize, i: usize) -> usize {
    (x >> i) & 1
}
fn main() {
    input! { n: usize }
    input! { s: [(char, usize); n] }

    let mut res = vec![0; 10];

    for bit in 0..10 {
        let mut r = 0;
        let mut k = true;
        for &(c, i) in s.iter().rev() {
            if c == '|' && getbit(i, bit) == 1 {
                res[bit] = 1 ^ r;
                k = false;
                break;
            }
            if c == '&' && getbit(i, bit) == 0 {
                res[bit] = r;
                k = false;
                break;
            }
            if c == '^' && getbit(i, bit) == 1 {
                r ^= 1;
            }
        }
        if k {
            res[bit] = r + 2;
        }
    }
    // eprintln!("{:?}", res);

    let mut out = vec![0; 3];
    for i in 0..10 {
        if res[i] != 0 {
            out[0] |= 1 << i;
        }
        if res[i] == 1 {
            out[1] |= 1 << i;
        }
        if res[i] == 3 {
            out[2] |= 1 << i;
        }
    }
    println!("3");
    println!("& {}", out[0]);
    println!("| {}", out[1]);
    println!("^ {}", out[2]);
}