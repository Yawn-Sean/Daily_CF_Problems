package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF916C(os.Stdin, os.Stdout) }

func CF916C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	var a1, num int
	if m == n-1 {
		a1 = 100019
		num = a1 + m - 1
		for !isPrime(num) {
			num += 1
		}
	} else {
		c := min916c(m-1, n-1)
		num = c
		for !isPrime(num) {
			num += 1
		}
		a1 = num
	}
	fmt.Fprintf(out, "%d %d\n", a1, num)
	fmt.Fprintf(out, "%d %d %d\n", 1, n, 100019)
	if m > 1 {
		count := 1
		for count < m-1 && count < n-1 {
			fmt.Fprintf(out, "%d %d %d\n", count, count+1, 1)
			count += 1
		}
		if m == n-1 {
			fmt.Fprintf(out, "%d %d %d\n", count, count+1, num-count-100019+1)
		} else {
			fmt.Fprintf(out, "%d %d %d\n", count, count+1, num-count+1)
		}
		count += 1
		for i := 1; i <= n; i++ {
			for j := i + 2; j <= n; j++ {
				if i == 1 && j == n {
					continue
				}
				if count == m {
					return
				}
				fmt.Fprintf(out, "%d %d %d\n", i, j, int(1e8))
				count += 1
			}
		}
	}
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false // 偶数（除了2）不是质数
	}

	// 只需检查从3到√n之间的奇数
	for i := 3; i*i <= n; i += 2 {
		if n%i == 0 {
			return false
		}
	}

	return true
}

func min916c(a, b int) int {
	if a < b {
		return a
	}
	return b
}
