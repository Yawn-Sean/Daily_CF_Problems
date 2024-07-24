func solve(out io.Writer) {
	n, q := readInt(), readInt()
	t := bits.Len64(uint64(n)) - 1
	for ; q > 0; q-- {
		s := readInt()
		op := readString()
		l := t - bits.TrailingZeros64(uint64(s))
		for _, ch := range op {
			if ch == 'L' {
				if l < t {
					l++
					s -= (s & -s) >> 1
				}
			} else if ch == 'R' {
				if l < t {
					l++
					s += (s & -s) >> 1
				}
			} else {
				if l > 0 {
					if s>>(t+1-l)&1 == 1 {
						s -= s & -s
					} else {
						s += s & -s
					}
					l--
				}
			}
		}
		fmt.Fprintln(out, s)
	}
}
 
func main() {
	out := bufio.NewWriter(os.Stdout)
	solve(out)
	out.Flush()
}
