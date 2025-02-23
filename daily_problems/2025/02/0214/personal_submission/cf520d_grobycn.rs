//! core logic only
//! submission: https://codeforces.com/problemset/submission/520/306536963
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_009;

fn solver(cubes: Vec<(i32, i32)>) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::{BinaryHeap, HashMap};

    let m = cubes.len();
    let mut hp1 = BinaryHeap::new();
    let mut hp2 = BinaryHeap::new();
    let mut used = vec![false; m];
    let mut nums = HashMap::new();
    for (i, &(x, y)) in cubes.iter().enumerate() {
        nums.insert((x, y), i);
    }

    let removable = |nums: &HashMap<(i32, i32), usize>, x: i32, y: i32| {
        for upperx in [x - 1, x, x + 1] {
            if nums.contains_key(&(upperx, y + 1)) {
                let mut cnt = 0;
                for lowerx in [upperx - 1, upperx, upperx + 1] {
                    if nums.contains_key(&(lowerx, y)) {
                        cnt += 1;
                    }
                }
                if cnt == 1 {
                    return false;
                }
            }
        }
        true
    };

    for (i, &(x, y)) in cubes.iter().enumerate() {
        if removable(&nums, x, y) {
            hp1.push(i);
            hp2.push(Reverse(i));
        }
    }

    let mut ans = 0;
    for i in 0..m {
        loop {
            let mut selected = usize::MAX;
            if i & 1 == 0 {
                while let Some(x) = hp1.pop() {
                    if !used[x] {
                        selected = x;
                        break;
                    }
                }
            } else {
                while let Some(Reverse(x)) = hp2.pop() {
                    if !used[x] {
                        selected = x;
                        break;
                    }
                }
            }
            let (x, y) = cubes[selected];
            if removable(&nums, x, y) {
                ans = ans * m + selected;
                ans %= MOD;
                nums.remove(&(x, y));
                used[selected] = true;
                for y in [y - 1, y + 1] {
                    for x in [x - 1, x, x + 1] {
                        if let Some(&i) = nums.get(&(x, y)) {
                            if removable(&nums, x, y) {
                                hp1.push(i);
                                hp2.push(Reverse(i));
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    ans
}
