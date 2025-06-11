package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF513B2(os.Stdin, os.Stdout) }

//if __name__ == '__main__':
//	print()
//	li = [1, 2, 3, 4]
//	n = 4
//	for e in list(permutations(li)):
//		c = 0
//		for i in range(n):
//			for j in range(i, n):
//				mn = 1000
//				for k in range(i, j + 1):
//					mn = min(mn, e[k])
//				c += mn
//		if c == 20:
//			print(e, c)

// 打表找规律，不会证
// (1, 2, 3, 4) 20
// (1, 2, 4, 3) 20
// (1, 3, 4, 2) 20
// (1, 4, 3, 2) 20
// (2, 3, 4, 1) 20
// (2, 4, 3, 1) 20
// (3, 4, 2, 1) 20
// (4, 3, 2, 1) 20

func CF513B2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	v := 1 << (n - 1)
	ans := make([]int, n)
	l, r := 0, n-1
	i := 1
	for v > 0 {
		v >>= 1
		if v < m {
			m -= v
			ans[r] = i
			r--
		} else {
			ans[l] = i
			l++
		}
		i++
	}
	for _, e := range ans {
		fmt.Fprintf(out, "%d ", e)
	}
}
