package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1195D2(os.Stdin, os.Stdout) }

func CF1195D2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	c := make([]int, 11)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		v := a[i]
		count := 0
		for v > 0 {
			count++
			v /= 10
		}
		c[count] += 1
	}
	ans := 0
	mod := 998244353
	for i := 0; i < n; i++ {
		v := a[i]
		cv, cv_ := 0, 0
		base := 1
		for j := 1; j <= 10; j++ {
			r := v % 10
			v /= 10
			cv_ += r * base
			base = (base * 10) % mod
			cv += r * base
			if v == 0 {
				ans = (ans + (cv+cv_)*c[j]) % mod
			} else {
				base2 := base
				cv2, cv2_ := cv, cv_
				v2 := v
				for v2 > 0 {
					r2 := v2 % 10
					v2 /= 10
					base2 = (base2 * 10) % mod
					cv2 += r2 * base2
					cv2_ += r2 * base2
				}
				ans = (ans + (cv2+cv2_)*c[j]) % mod
			}
			base = (base * 10) % mod
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
}
