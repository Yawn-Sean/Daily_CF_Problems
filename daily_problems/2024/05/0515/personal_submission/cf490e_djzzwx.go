# Submission link: https://codeforces.com/contest/490/submission/261014930
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	Fscan(in, &n)
	a := make([][]byte, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	f0 := func(c []byte) []byte {
		if c[0] == '?' {
			c[0] = '1'
		}
		for i := 1; i < len(c); i++ {
			if c[i] == '?' {
				c[i] = '0'
			}
		}
		return c
	}
	f1 := func(a, b []byte) ([]byte, error) {
		for i := 0; i < len(a); i++ {
			if b[i] == '?' || a[i] == b[i] {
				continue
			}
			if a[i] < b[i] {
				for j := i - 1; j >= 0; j-- {
					if b[j] == '?' {
						b[j] = a[j]
					}
				}
				for j := i; j < len(a); j++ {
					if b[j] == '?' {
						b[j] = '0'
					}
				}
				return b, nil
			} else if a[i] > b[i] {
				for j := i - 1; j >= 0; j-- {
					if b[j] == '?' && a[j] < '9' {
						b[j] = a[j] + 1
						for k := j; k < len(a); k++ {
							if b[k] == '?' {
								b[k] = '0'
							}
						}
						for j--; j >= 0; j-- {
							if b[j] == '?' {
								b[j] = a[j]
							}
						}
						return b, nil
					}
				}
				return b, errors.New("err2")
			}
		}
		for j := len(a) - 1; j >= 0; j-- {
			if b[j] == '?' && a[j] < '9' {
				b[j] = a[j] + 1
				for k := j; k < len(a); k++ {
					if b[k] == '?' {
						b[k] = '0'
					}
				}
				for j--; j >= 0; j-- {
					if b[j] == '?' {
						b[j] = a[j]
					}
				}
				return b, nil
			}
		}
		return []byte{}, errors.New("err")
	}
	p := []byte{}
	for i, v := range a {
		if len(v) < len(p) {
			Fprintln(out, "NO")
			return
		} else if len(v) > len(p) {
			a[i] = f0(v)
			p = a[i]
			continue
		}
		c, err := f1(p, v)
		if err != nil {
			Fprintln(out, "NO")
			//for _, v := range a {
			//	Fprintln(out, string(v))
			//}
			return
		}
		a[i] = c
		p = a[i]
	}
	Fprintln(out, "YES")
	for _, v := range a {
		Fprintln(out, string(v))
	}
}
