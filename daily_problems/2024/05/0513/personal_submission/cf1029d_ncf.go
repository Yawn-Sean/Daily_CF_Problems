package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1029D(os.Stdin, os.Stdout) }

func CF1029D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	a := make([]int, n)
	m := make([]map[int]int, 11)
	for i := 1; i < 11; i++ {
		m[i] = map[int]int{}
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		remainder := a[i] % k
		for j := 1; j < 11; j++ {
			remainder = remainder * 10 % k
			m[j][remainder] += 1
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		c1, c2 := a[i], a[i]%k
		count := 0
		for c1 > 0 {
			c2 = c2 * 10 % k
			count += 1
			c1 /= 10
		}
		ans += m[count][(k-a[i]%k)%k]
		if c2 == (k-a[i]%k)%k {
			ans -= 1
		}
	}
	fmt.Fprintf(out, "%d", ans)
}
