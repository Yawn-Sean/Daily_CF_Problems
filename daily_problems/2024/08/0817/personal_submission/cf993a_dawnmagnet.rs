fn main() {
    input! {p: [i32; 16]}
    let px = (
        p[0].min(p[2]).min(p[4]).min(p[6]),
        p[0].max(p[2]).max(p[4]).max(p[6]),
    );
    let py = (
        p[1].min(p[3]).min(p[5]).min(p[7]),
        p[1].max(p[3]).max(p[5]).max(p[7]),
    );

    let check = |x1: i32, y1: i32, x2: i32, y2: i32, x3: i32, y3: i32| {
        let d1 = if x2 > x1 { 1 } else { -1 };
        let d2 = if y2 > y1 { 1 } else { -1 };
        let d3 = if x3 > x2 { 1 } else { -1 };
        let d4 = if y3 > y2 { 1 } else { -1 };
        for i in 0i32..=((x2 - x1).abs()) {
            for j in 0i32..=((y2 - y1).abs()) {
                let x = x1 + i * d1 + j * d3;
                let y = y1 + i * d2 + j * d4;
                if px.0 <= x && x <= px.1 && py.0 <= y && y <= py.1 {
                    return true;
                }
            }
        }
        false
    };
    let r = check(p[8], p[9], p[10], p[11], p[12], p[13]);
    println!("{}", if r { "YES" } else { "NO" });
}