package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, l int
	fmt.Fscan(in, &n, &l)

	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &w[i])
	}
	for i := 1; i < n; i++ {
		w[i] = min(w[i], w[i-1]*2)
	}

	ans := math.MaxInt
	curr := 0
	for i := n - 1; i >= 0; i-- {
		cnt := (l-1)/(1<<i) + 1
		ans = min(ans, curr+w[i]*cnt)
		v := l / (1 << i)
		l -= v << i
		curr += v * w[i]
	}
	fmt.Fprintln(out, ans)
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
