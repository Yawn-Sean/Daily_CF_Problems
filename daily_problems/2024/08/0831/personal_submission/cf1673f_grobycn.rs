//! core logic only
//! submission: https://codeforces.com/contest/1673/submission/279087083
const MULTIPLE_TEST: bool = false;

fn interleave(x: usize, y: usize) -> usize {
    // https://graphics.stanford.edu/~seander/bithacks.html#Interleave64bitOps
    let even_bits = (((x * 0x0101010101010101) & 0x8040201008040201).wrapping_mul(0x0102040810204081) >> 49) & 0x5555;
    let odd_bits = (((y * 0x0101010101010101) & 0x8040201008040201).wrapping_mul(0x0102040810204081) >> 48) & 0xAAAA;
    even_bits | odd_bits
}

fn gray_code(code: &mut [usize], k: usize) {
    if k == 0 {
        code[0] = 0;
        return;
    }
    let n = 1 << (k - 1);
    gray_code(&mut code[..n], k - 1);
    for i in 0..n {
        code[2 * n - 1 - i] = code[i] | n;
    }
}

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut code = [0; 32];
    gray_code(&mut code, 5);
    let mut xor_mat = [[0; 32]; 32];
    let mut pos = [(0, 0); 1024];

    for r in 0..32 {
        for c in 0..32 {
            let idx = interleave(code[r], code[c]);
            xor_mat[r][c] = idx;
            pos[idx] = (r + 1, c + 1);
        }
    }

    for row in xor_mat[..n].iter() {
        for (i, w) in row[..n].windows(2).enumerate() {
            if i == 0 {
                print!("{}", w[0] ^ w[1]);
            } else {
                print!(" {}", w[0] ^ w[1]);
            }
        }
        println!();
    }
    for w in xor_mat[..n].windows(2) {
        for c in 0..n {
            if c == 0 {
                print!("{}", w[0][c] ^ w[1][c]);
            } else {
                print!(" {}", w[0][c] ^ w[1][c]);
            }
        }
        println!();
    }

    let mut xor = 0;
    for _ in 0..k {
        xor ^= usize::from_scanner(scanner);
        let (r, c) = pos[xor];
        println!("{} {}", r, c);
    }
    ""
}
