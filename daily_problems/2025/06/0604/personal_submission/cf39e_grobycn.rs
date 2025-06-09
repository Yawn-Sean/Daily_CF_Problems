//! core logic only
//! submission: https://codeforces.com/problemset/submission/39/322877510
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, n: usize) -> impl Printable {
    enum Result {
        Win,
        Lose,
        Draw,
    }

    fn dp(a: usize, b: usize, n: usize) -> Result {
        if a == 1 {
            if (a + 1).saturating_pow(b as u32) >= n {
                return Result::Draw;
            }
            return match dp(a + 1, b, n) {
                Result::Win => match dp(a, b + 1, n) {
                    Result::Lose => Result::Win,
                    Result::Win => Result::Lose,
                    Result::Draw => Result::Draw,
                },
                Result::Lose => Result::Win,
                _ => unreachable!(),
            };
        }
        if a.saturating_pow(b as u32) >= n {
            return Result::Win;
        }
        match dp(a, b + 1, n) {
            Result::Lose => Result::Win,
            Result::Win => match dp(a + 1, b, n) {
                Result::Lose => Result::Win,
                Result::Win => Result::Lose,
                Result::Draw => unreachable!(),
            },
            Result::Draw => unreachable!(),
        }
    }
    match dp(a, b, n) {
        Result::Win => "Masha",
        Result::Lose => "Stas",
        Result::Draw => "Missing",
    }
}
