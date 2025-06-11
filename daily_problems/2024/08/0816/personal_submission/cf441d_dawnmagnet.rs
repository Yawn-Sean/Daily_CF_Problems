fn main() {
    input! {
        n: usize,
        mut a: [usize; n],
        m: usize
    }
    a.insert(0, 0);
    let mut vis = vec![false; n + 1];
    let mut circles = 0;
    let mut cs = vec![];
    for i in 1..=n {
        if !vis[i] {
            circles += 1;
            cs.push(i);
            let mut x = i;
            while !vis[x] {
                vis[x] = true;
                x = a[x];
            }
        }
    }
    let target = n - m;
    let mut td = target.abs_diff(circles);
    println!("{}", td);
    // println!("{:?}", cs);
    if circles > target {
        for i in 1..=td {
            print!("{} {} ", 1, cs[i]);
        }
        return;
    }
    if circles < target {
        for _i in 0..td {
            for i in 1..=n {
                if a[i] != i {
                    vis = vec![false; n + 1];
                    let mut x = i;
                    while !vis[x] {
                        vis[x] = true;
                        x = a[x];
                    }
                    break;
                }
            }
            let mut v1 = vec![];
            for i in 1..=n {
                if vis[i] {
                    v1.push(i);
                    if v1.len() == 2 {
                        break;
                    }
                }
            }
            a.swap(v1[0], v1[1]);
            print!("{} {} ", v1[0], v1[1]);
        }
    }
}