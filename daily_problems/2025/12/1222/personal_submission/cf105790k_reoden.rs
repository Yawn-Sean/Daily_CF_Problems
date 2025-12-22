fn exp_calc() -> u64 {
    let n: u64 = read();
    if n <= 1 {
        return n;
    }
    let mut base_m: Matrix = Matrix::new(2);
    base_m.data[0][0] = ModInt(1);
    base_m.data[1][0] = ModInt(1);
    base_m.data[0][1] = ModInt(1);

    base_m = base_m.pow(n - 2);
    let res = base_m.mul_vec(&vec![ModInt(1); 2]);
    let p = res[0];
    p.0 as u64
}

fn main() {
    let mut ans = ModInt2(2);
    let exp = exp_calc();
    ans = ans.power(exp);
    output!(ans);
}
