# Submission link: https://codeforces.com/contest/914/submission/260869933
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	var k int
	Fscan(in, &s, &k)
	if k == 0 {
		Fprintln(out, 1)
		return
	}
	if k == 1 {

	}
	const mod int = 1e9 + 7
	cnt := [1001]int{}
	for i := 2; i <= 1000; i++ {
		cnt[i] = cnt[bits.OnesCount(uint(i))] + 1
	}
	rel := map[int]bool{}
	for i, c := range cnt {
		if c == k-1 {
			rel[i] = true
		}
	}
	m := len(s)
	memo := make([][1 << 10]int, m)
	for i := range memo {
		for j := range memo[i] {
			memo[i][j] = -1 // -1 表示没有计算过
		}
	}
	var f func(int, int, bool, bool) int
	f = func(i, mask int, isLimit, isNum bool) (res int) {
		if i == m {
			if isNum && rel[mask] {
				return 1 // 得到了一个合法数字
			}
			return
		}
		if !isLimit && isNum {
			p := &memo[i][mask]
			if *p >= 0 {
				return *p
			}
			defer func() { *p = res }()
		}
		if !isNum { // 可以跳过当前数位
			res += f(i+1, mask, false, false)
		}
		d := 0
		if !isNum {
			d = 1 // 如果前面没有填数字，必须从 1 开始（因为不能有前导零）
		}
		up := 1
		if isLimit {
			up = int(s[i] - '0') // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
		}
		for ; d <= up; d++ { // 枚举要填入的数字 d
			res += f(i+1, mask+d, isLimit && d == up, true)
			res %= mod
		}
		return
	}
	ans := f(0, 0, true, false) % mod
	if k == 1 {
		ans--
	}
	Fprintln(out, ans)
}