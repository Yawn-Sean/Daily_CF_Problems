struct Container {
    long long tot: 64;
    int vol: 32;
    int sz: 32;
}

fn op(c1: Container, c2: Container) -> Container {
    if c1.sz == 0 {
        return c2;
    }
    if c2.sz == 0 {
        return c1;
    }
    Container {
        tot: c1.tot + c2.tot + 1ll * (c2.vol - c1.vol) * c1.sz,
        vol: c2.vol,
        sz: c1.sz + c2.sz,
    }
}

fn e() -> Container {
    Container { tot: 0, vol: 0, sz: 0 }
}

fn main() {
    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
    let n = iter.next().unwrap().parse().unwrap();
    let q = iter.next().unwrap().parse().unwrap();

    let mut nums = vec![0; n];
    for i in 0..n {
        nums[i] = iter.next().unwrap().parse().unwrap();
    }

    let mut volumes = nums.clone();
    let mut xs = vec![-1; q];
    let mut ys = vec![0; q];
    for i in 0..q {
        let typ = iter.next().unwrap().parse().unwrap();
        if typ == 1 {
            let x = iter.next().unwrap().parse().unwrap();
            let y = iter.next().unwrap().parse().unwrap();
            xs[i] = x as i32 - 1;
            volumes.push(y);
        } else {
            let y = iter.next().unwrap().parse().unwrap();
            ys[i] = y;
        }
    }
    volumes.sort();
    let k = volumes.iter().unique().cloned().count();

    let mut mp = std::collections::HashMap::new();
    for i in 0..k {
        mp.insert(volumes[i], i);
    }

    let mut ar = vec![e(); k];
    for i in 0..n {
        ar[mp[nums[i]]].sz += 1;
    }

    let seg = segtree::Segtree::new(ar, op, e);

    let mut output = String::new();
    for i in 0..q {
        if xs[i] != -1 {
            let idx = mp[nums[xs[i] as usize]];
            ar[idx].sz -= 1;
            seg.set(idx, ar[idx]);

            nums[xs[i] as usize] = ys[i];

            let idx = mp[nums[xs[i] as usize]];
            ar[idx].sz += 1;
            seg.set(idx, ar[idx]);
        } else {
            let ans = seg.prod(0, seg.max_right(0, |c| c.tot <= ys[i]));
            output.push_str(&format!("{:.10}", 1.0 * (ys[i] - ans.tot) / ans.sz + ans.vol));
            output.push('\n');
        }
    }

    stdout.write_all(output.as_bytes()).unwrap();
}