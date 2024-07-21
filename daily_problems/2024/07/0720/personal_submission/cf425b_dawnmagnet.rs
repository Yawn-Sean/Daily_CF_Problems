use std::vec;

mod io {
    #[macro_export]
    macro_rules! input {
        () => {};
        (mut $var:ident: $t:tt, $($rest:tt)*) => {
            let mut $var = __input_inner!($t);
            input!($($rest)*)
        };
        ($var:ident: $t:tt, $($rest:tt)*) => {
            let $var = __input_inner!($t);
            input!($($rest)*)
        };
        (mut $var:ident: $t:tt) => {
            let mut $var = __input_inner!($t);
        };
        ($var:ident: $t:tt) => {
            let $var = __input_inner!($t);
        };
    }

    #[macro_export]
    macro_rules! __input_inner {
        (($($t:tt),*)) => {
            ($(__input_inner!($t)),*)
        };
        ([$t:tt; $n:expr]) => {
            (0..$n).map(|_| __input_inner!($t)).collect::<Vec<_>>()
        };
        ([$t:tt]) => {{
            let n = __input_inner!(usize);
            (0..n).map(|_| __input_inner!($t)).collect::<Vec<_>>()
        }};
        (chars) => {
            __input_inner!(String).chars().collect::<Vec<_>>()
        };
        (bytes) => {
            __input_inner!(String).into_bytes()
        };
        (usize1) => {
            __input_inner!(usize) - 1
        };
        ($t:ty) => {
            $crate::io::read::<$t>()
        };
    }
    #[allow(unused)]
    pub fn read<T>() -> T
    where
        T: std::str::FromStr,
        T::Err: std::fmt::Debug,
    {
        use std::cell::RefCell;
        use std::io::*;

        thread_local! {
            pub static STDIN: RefCell<StdinLock<'static>> = RefCell::new(stdin().lock());
        }

        STDIN.with(|r| {
            let mut r = r.borrow_mut();
            let mut s = vec![];
            loop {
                let buf = r.fill_buf().unwrap();
                if buf.is_empty() {
                    break;
                }
                if let Some(i) = buf.iter().position(u8::is_ascii_whitespace) {
                    s.extend_from_slice(&buf[..i]);
                    r.consume(i + 1);
                    if !s.is_empty() {
                        break;
                    }
                } else {
                    s.extend_from_slice(buf);
                    let n = buf.len();
                    r.consume(n);
                }
            }
            std::str::from_utf8(&s).unwrap().parse().unwrap()
        })
    }

    #[macro_export]
    macro_rules! println {
        ($($arg:tt)*) => {
            $crate::io::write(|w| {
                use std::io::Write;
                std::writeln!(w, $($arg)*).unwrap()
            })
        };
    }

    #[macro_export]
    macro_rules! print {
        ($($arg:tt)*) => {
            $crate::io::write(|w| {
                use std::io::Write;
                std::write!(w, $($arg)*).unwrap()
            })
        };
    }

    #[macro_export]
    macro_rules! flush {
        () => {
            $crate::io::write(|w| {
                use std::io::Write;
                w.flush().unwrap()
            })
        };
    }
    #[allow(unused)]
    pub fn write<F>(f: F)
    where
        F: FnOnce(&mut std::io::BufWriter<std::io::StdoutLock>),
    {
        use std::cell::RefCell;
        use std::io::*;

        thread_local! {
            pub static STDOUT: RefCell<BufWriter<StdoutLock<'static>>> =
                RefCell::new(BufWriter::new(stdout().lock()));
        }

        STDOUT.with(|w| f(&mut w.borrow_mut()))
    }
}

fn main() {
    input! { n: usize, m: usize, k: usize }
    input! { v: [[u8; m]; n] }

    // println!("{:?}", v);
    let mut res = 1000000;

    if m > k {
        let mut bin: Vec<i128> = vec![0; m];
        for i in 0..n {
            for j in 0..m {
                if v[i][j] == 1 {
                    bin[j] ^= 1 << i;
                }
            }
        }
        for i in 0..m {
            let mut cnt = 0;
            for j in 0..m {
                let t = (bin[j] ^ bin[i]).count_ones();
                cnt += t.min(n as u32 - t);
            }
            res = res.min(cnt);
        }
        res
    } else {
        let mut bin: Vec<i128> = vec![0; n];
        for i in 0..n {
            for j in 0..m {
                if v[i][j] == 1 {
                    bin[i] ^= 1 << j;
                }
            }
        }
        let mut res = 1000000;
        for tr in 0..(1 << m) {
            let mut cnt = 0;
            for i in 0..n {
                let t = (bin[i] ^ tr).count_ones();
                cnt += t.min(m as u32 - t);
            }
            res = res.min(cnt);
        }
        res
    }
    if res <= k as u32 {
        println!("{}", res);
    } else {
        println!("-1");
    }
}
