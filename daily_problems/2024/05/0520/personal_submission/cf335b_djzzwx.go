# Submission link: https://codeforces.com/contest/335/submission/261743531
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	Fscan(in, &s)
	cnt := [26]int{}
	for _, b := range s {
		cnt[b-'a']++
		if cnt[b-'a'] == 100 {
			Fprintln(out, strings.Repeat(string(b), 100))
			return
		}
	}
	n := len(s)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		f[i][i] = 1
	}
	for l := n - 1; l >= 0; l-- {
		for r := l + 1; r < n; r++ {
			if s[l] == s[r] {
				f[l][r] = f[l+1][r-1] + 2
			} else {
				f[l][r] = max(f[l+1][r], f[l][r-1])
			}
		}
	}
	a := []byte{}
	l, r := 0, n-1
	for l < r {
		if s[l] == s[r] {
			a = append(a, s[l])
			l++
			r--
		} else if f[l][r] == f[l+1][r] {
			l++
		} else {
			r--
		}
	}
	if len(a) > 50 {
		a = a[:50]
	}
	i := len(a) - 1
	if len(a) < 50 && l == r {
		a = append(a, s[l])
	}
	for ; i >= 0; i-- {
		a = append(a, a[i])
	}
	Fprintln(out, string(a))
}