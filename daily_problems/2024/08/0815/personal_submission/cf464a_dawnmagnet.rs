fn main() {
    input! { n: usize, p: u8 }
    input! { k: String }
    let mut b = k.into_bytes();
    for i in b.iter_mut() {
        *i -= b'a';
    }
    let mut add = |pos: usize, b: &mut Vec<u8>| -> Option<usize> {
        for i in (0..=pos).rev() {
            if b[i] + 1 < p {
                b[i] += 1;
                return Some(i);
            } else {
                b[i] = 0;
            }
        }
        None
    };
    let output = |b: &Vec<u8>| {
        for i in b.iter() {
            print!("{}", (i + b'a') as char);
        }
        println!();
    };
    let mut r = add(n - 1, &mut b);
    while let Some(i) = r {
        // output(&b);
        if i == n {
            output(&b);
            return;
        }
        if i >= 1 && b[i] == b[i - 1] || i >= 2 && b[i] == b[i - 2] {
            r = add(i, &mut b);
        } else {
            r = Some(i + 1);
        }
    }
    println!("NO");
}