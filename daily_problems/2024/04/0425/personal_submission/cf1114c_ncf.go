package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF1114C(os.Stdin, os.Stdout) }

func CF1114C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, b int
	fmt.Fscan(in, &n, &b)
	factors := getPrimeFactors1114c(b)
	ans := math.MaxInt
	for k, v := range factors {
		cur := n
		count := 0
		for cur > 0 {
			cur /= k
			count += cur
		}
		ans = min(ans, count/v)
	}
	fmt.Fprintf(out, "%d\n", ans)
}

func getPrimeFactors1114c(n int) (factors map[int]int) {
	i := 2
	factors = map[int]int{}

	for i*i <= n {
		for n%i == 0 {
			factors[i] += 1
			n /= i
		}
		i += 1
	}
	if n > 1 {
		factors[n] += 1
	}
	return
}
