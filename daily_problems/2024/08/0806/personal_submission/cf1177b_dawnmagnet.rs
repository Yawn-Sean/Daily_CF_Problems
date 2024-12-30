fn main() {
    input! {mut x: i64}
    x -= 1;
    let mut cur = 9;
    for i in 1..100000 {
        if x >= cur * i {
            x -= cur * i;
            cur *= 10;
        } else {
            let j = x / i + cur / 9;
            let p = x % i;
            // print!("{i} ({x} {j} {p}) \n");
            let ps = j.to_string();
            println!("{}", ps.chars().nth(p as usize).unwrap());
            return;
        }
    }
}