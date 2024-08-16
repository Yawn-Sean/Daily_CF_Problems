fn main() {
    input! { n: usize, a: [i32; n] }
    let mut tasks = vec![];
    let mut values = vec![];
    for (id, &x) in a.iter().enumerate() {
        let j = id as i32 + 1;
        tasks.push((1, x.min(n as i32), j));
        values.push((j, x));
    }
    values.sort_unstable_by_key(|x| x.1);
    tasks.sort_unstable_by_key(|x| x.2);

    // println!("{:?}", tasks);
    let mut tree = FenwickTree::new(n + 1);

    let mut res = 0;

    for (l, r, v) in tasks.into_iter().rev() {
        while !values.is_empty() && values.last().unwrap().1 >= v {
            let (j, _x) = values.pop().unwrap();
            tree.add(j as usize, 1);
        }
        res += tree.sum_range(l as usize, r as usize);
        if a[v as usize - 1] >= v {
            res -= 1;
        }
    }
    println!("{}", res / 2);
}