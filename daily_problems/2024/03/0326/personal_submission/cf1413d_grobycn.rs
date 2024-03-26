// core logic only
// submission: https://codeforces.com/problemset/submission/1413/253350680
const MULTIPLE_TEST: bool = false;

#[derive(Clone, Copy)]
enum Op {
    Push,
    Pop(usize),
}

impl FromScanner for Op {
    fn from_scanner(scanner: &mut Scanner) -> Self {
        if String::from_scanner(scanner) == "+" {
            Op::Push
        } else {
            Op::Pop(usize::from_scanner(scanner))
        }
    }
}

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let ops: Vec<Op> = scanner.iter(2 * n).collect();
    let mut st = vec![];
    let mut ans = vec![0; n];
    let mut idx = 0;
    for &op in &ops {
        match op {
            Op::Push => {
                st.push(idx);
                idx += 1;
            }
            Op::Pop(x) => match st.pop() {
                Some(i) => ans[i] = x,
                _ => return Err("NO"),
            },
        }
    }

    let mut hp = BinaryHeap::new();
    let mut it = ans.iter();
    for op in ops {
        match op {
            Op::Push => match it.next() {
                Some(&x) => hp.push(Reverse(x)),
                _ => unreachable!(),
            },
            Op::Pop(x) => match hp.pop() {
                Some(Reverse(y)) if y == x => {}
                _ => return Err("NO"),
            },
        }
    }

    Ok("YES".cr().then(Sep::<_, ' '>(ans)))
}
