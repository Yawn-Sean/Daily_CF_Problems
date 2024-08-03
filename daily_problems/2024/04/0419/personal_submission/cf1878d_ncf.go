package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1878D(os.Stdin, os.Stdout) }

func CF1878D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k, q, x int
	fmt.Fscan(in, &t)
	var s string
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k, &s)
		l, r := make([]int, k), make([]int, k)
		for i := 0; i < k; i++ {
			fmt.Fscan(in, &l[i])
		}
		for i := 0; i < k; i++ {
			fmt.Fscan(in, &r[i])
		}
		fmt.Fscan(in, &q)
		f := make([]int, n+1)
		for i := 0; i < q; i++ {
			fmt.Fscan(in, &x)
			//idx, _ := slices.BinarySearch(l, x)  codeforces go版本过低，不支持这个函数
			lll, rrr := 0, len(l)-1
			for lll <= rrr {
				mid := (lll + rrr) / 2
				if l[mid] >= x {
					rrr = mid - 1
				} else {
					lll = mid + 1
				}
			}
			idx := lll
			if idx >= len(l) || x != l[idx] {
				idx -= 1
			}
			cl, cr := l[idx], r[idx]
			mn, mx := minMax1878d(x, cl+cr-x)
			f[mn-1] += 1
			f[mx] -= 1
		}
		ll, rr, idx := -1, -1, 0
		ans := make([]uint8, n)
		for i := 0; i < n; i++ {
			if i > rr {
				ll, rr, idx = i, r[idx]-1, idx+1
			}
			if i > 0 {
				f[i] += f[i-1]
			}
			if f[i]&1 == 0 {
				ans[i] = s[i]
			} else {
				ans[i] = s[ll+rr-i]
			}
		}
		fmt.Fprintf(out, "%s\n", string(ans))
	}
}

func minMax1878d(a, b int) (int, int) {
	if a < b {
		return a, b
	}
	return b, a
}
