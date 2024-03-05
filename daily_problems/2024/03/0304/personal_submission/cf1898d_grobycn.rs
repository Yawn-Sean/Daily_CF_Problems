//! my template file for codeforces
//! author: YummyPie
//!
//! impl your solver function
//! don't change the function name, unless you change the name in main function too
//! you can change the arguments
//! specially, you can add `&mut Scanner` as last argument
//!
//! note: there is a special type `Mat<T>` which stands for matrix
//! a argument with type `Mat<T>` will read length of rows first, then the length of column, and
//! finally its elements
//!
//! as for `Vec<T>`, length comes first, then the elements
//! so if the length and the elements are seperated by other argument
//! you must use scanner to read elements mannually
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<i64>, scanner: &mut Scanner) -> impl Printable {
    let n = a.len();
    let b: Vec<i64> = scanner.iter(n).collect();
    let mut ans = 0;
    let mut mx = 0;
    let mut mn = i64::MAX;
    for (mut ai, mut bi) in a.into_iter().zip(b) {
        if ai < bi {
            std::mem::swap(&mut ai, &mut bi);
        }
        ans += ai - bi;
        mx = mx.max(bi);
        mn = mn.min(ai);
    }
    if mx > mn {
        ans += 2 * (mx - mn);
    }
    ans
}

fn main() {
    let mut scanner = Scanner::default();
    let mut writer = BufWriter::new(io::stdout());
    if MULTIPLE_TEST {
        solver.solve_many(&mut scanner, &mut writer);
    } else {
        solver.solve1(&mut scanner, &mut writer);
    }
}

use std::any::type_name;
use std::io::{self, stdin, BufWriter, Write};
use std::iter::FromIterator;
use std::marker::PhantomData;
use std::mem::transmute;
use std::str::{FromStr, SplitWhitespace};

// Scanner is copied from other guy's code, with a little modification
struct Scanner {
    buffer: String,
    tokens: SplitWhitespace<'static>,
}

impl Default for Scanner {
    fn default() -> Self {
        Self {
            buffer: String::new(),
            tokens: "".split_whitespace(),
        }
    }
}

impl Scanner {
    pub fn next<T: FromStr>(&mut self) -> T {
        let Self { buffer, tokens } = self;
        loop {
            if let Some(tok) = tokens.next() {
                match tok.parse() {
                    Ok(t) => return t,
                    _ => panic!("Failed to parse type {} from {}", type_name::<T>(), tok),
                }
            }
            buffer.clear();
            stdin().read_line(buffer).expect("Failed to read new line");
            // it is safe since we free the buffer only after the tokens are empty
            // and the types impl FromStr must be owned type.
            *tokens = unsafe { transmute(buffer.split_whitespace()) };
        }
    }
    #[allow(dead_code)]
    pub fn collect<T: FromScanner, I: FromIterator<T>>(&mut self, n: usize) -> I {
        self.iter(n).collect()
    }
    #[allow(dead_code)]
    pub fn iter<T: FromScanner>(&mut self, n: usize) -> Iter<'_, T> {
        Iter {
            n,
            scanner: self,
            _marker: PhantomData,
        }
    }
}

struct Iter<'a, T: FromScanner> {
    n: usize,
    scanner: &'a mut Scanner,
    _marker: PhantomData<T>,
}

impl<'a, T: FromScanner> Iterator for Iter<'a, T> {
    type Item = T;
    fn next(&mut self) -> Option<T> {
        if self.n > 0 {
            self.n -= 1;
            Some(T::from_scanner(self.scanner))
        } else {
            None
        }
    }
    fn size_hint(&self) -> (usize, Option<usize>) {
        (self.n, Some(self.n))
    }
}

impl<'a, T: FromScanner> Drop for Iter<'a, T> {
    fn drop(&mut self) {
        // eat the rest part in case we break loop early
        while self.next().is_some() {}
    }
}

trait FromScanner {
    fn from_scanner(scanner: &mut Scanner) -> Self;
}

macro_rules! impl_from_scanner_for {
    ($($t:ty),*) => {
        $(impl FromScanner for $t {
            fn from_scanner(scanner: &mut Scanner) -> Self {
                scanner.next()
            }
        })*
    }
}

impl_from_scanner_for!(
    bool, i8, u8, i16, u16, i32, u32, i64, u64, i128, u128, isize, usize, String
);

impl<T: FromScanner> FromScanner for Vec<T> {
    fn from_scanner(scanner: &mut Scanner) -> Self {
        let n: usize = scanner.next();
        (0..n).map(|_| T::from_scanner(scanner)).collect()
    }
}

struct Mat<T>(Vec<Vec<T>>);

impl<T: FromScanner> FromScanner for Mat<T> {
    fn from_scanner(scanner: &mut Scanner) -> Self {
        let (n, m) = (scanner.next(), scanner.next());
        let mat = (0..n)
            .map(|_| (0..m).map(|_| T::from_scanner(scanner)).collect())
            .collect();
        Mat(mat)
    }
}

macro_rules! for_tuples {
    ($name:ident) => {
        $name!(T1);
        $name!(T1, T2);
        $name!(T1, T2, T3);
        $name!(T1, T2, T3, T4);
        $name!(T1, T2, T3, T4, T5);
        $name!(T1, T2, T3, T4, T5, T6);
        $name!(T1, T2, T3, T4, T5, T6, T7);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
        $name!(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    };
}

macro_rules! impl_from_scanner {
    ($($t:ident),*) => {
        impl<$($t),*> FromScanner for ($($t,)*)
        where
            $($t: FromScanner),*
        {
            fn from_scanner(scanner: &mut Scanner) -> Self {
                ($($t::from_scanner(scanner),)*)
            }
        }
    }
}

for_tuples!(impl_from_scanner);

trait Solver<Args> {
    fn solve1<W: Write>(&self, scanner: &mut Scanner, w: &mut W);
    fn solve_many<W: Write>(&self, scanner: &mut Scanner, w: &mut W) {
        let t: usize = scanner.next();
        for _ in 0..t {
            self.solve1(scanner, w);
        }
    }
}

impl<F, Ans> Solver<Scanner> for F
where
    F: Fn(&mut Scanner) -> Ans,
    Ans: Printable,
{
    fn solve1<W: Write>(&self, scanner: &mut Scanner, w: &mut W) {
        let ans = self(scanner);
        Line(ans).print_to(w).unwrap();
    }
}

macro_rules! impl_solver {
    ($($t: ident),*) => {
        impl<F, Ans, $($t),*> Solver<($($t,)*)> for F
        where
            F: Fn($($t),*) -> Ans,
            Ans: Printable,
            $($t: FromScanner),*
        {
            fn solve1<W: Write>(&self, scanner: &mut Scanner, w: &mut W) {
                let ans = self($($t::from_scanner(scanner)),*);
                Line(ans).print_to(w).unwrap();
            }
        }
        impl<F, Ans, $($t),*> Solver<($($t),*, Scanner)> for F
        where
            F: Fn($($t),*, &mut Scanner) -> Ans,
            Ans: Printable,
            $($t: FromScanner),*
        {
            fn solve1<W: Write>(&self, scanner: &mut Scanner, w: &mut W) {
                let ans = self($($t::from_scanner(scanner)),*, scanner);
                Line(ans).print_to(w).unwrap();
            }
        }
    }
}

for_tuples!(impl_solver);

trait Printable {
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()>;
    fn cr(self) -> Line<Self>
    where
        Self: Sized,
    {
        Line(self)
    }
    fn then<P: Printable>(self, p: P) -> Concat<Self, P>
    where
        Self: Sized,
    {
        Concat(self, p)
    }
}

macro_rules! impl_printable_for {
    ($($t:ty),*) => {
        $(impl Printable for $t {
            fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
                write!(w, "{}", self)
            }
        })*
    }
}

impl_printable_for!(
    bool,
    char,
    u8,
    i8,
    u16,
    i16,
    u32,
    i32,
    u64,
    i64,
    u128,
    i128,
    usize,
    isize,
    String,
    &'static str
);

struct Line<T>(T);
impl<T: Printable> Printable for Line<T> {
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        self.0.print_to(w)?;
        writeln!(w)
    }
}

struct Concat<L, R>(L, R);
impl<L: Printable, R: Printable> Printable for Concat<L, R> {
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        self.0.print_to(w)?;
        self.1.print_to(w)
    }
}

struct Flush<T>(T);
impl<T: Printable> Printable for Flush<T> {
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        self.0.print_to(w)?;
        w.flush()
    }
}

impl<Yes, No> Printable for Result<Yes, No>
where
    Yes: Printable,
    No: Printable,
{
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        match self {
            Ok(yes) => yes.print_to(w),
            Err(no) => no.print_to(w),
        }
    }
}

struct Sep<I, const S: char = ' '>(I);
impl<const S: char, I, T> Printable for Sep<I, S>
where
    I: IntoIterator<Item = T>,
    T: Printable,
{
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        let mut it = self.0.into_iter();
        if let Some(first) = it.next() {
            first.print_to(w)?;
        }
        for e in it {
            S.print_to(w)?;
            e.print_to(w)?;
        }
        Ok(())
    }
}
impl<T> Printable for Mat<T>
where
    T: Printable,
{
    fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
        // layout is same with Vec<Vec<T>>, so it's safe here
        let mat: Sep<Vec<Sep<Vec<T>, ' '>>, '\n'> = unsafe { transmute(self) };
        mat.print_to(w)
    }
}

macro_rules! impl_printable {
    ($($t: ident),*) => {
        impl<$($t),*> Printable for ($($t,)*)
        where
            $($t: Printable),*
        {
            #[allow(non_snake_case)]
            #[allow(unused_assignments)]
            fn print_to<W: Write>(self, w: &mut W) -> io::Result<()> {
                let ($($t,)*) = self;
                let mut add_space = false;
                $({
                    if add_space {
                        write!(w, " ")?;
                    } else {
                        add_space = true;
                    }
                    $t.print_to(w)?;
                })*
                Ok(())
            }
        }
    }
}

for_tuples!(impl_printable);
