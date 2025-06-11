package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF420C(os.Stdin, os.Stdout) }

func CF420C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, p, a, b int
	fmt.Fscan(in, &n, &p)
	type tuple struct {
		a, b int
	}
	count := make([]int, n)
	repeat := map[tuple]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a, &b)
		a, b = a-1, b-1
		if a > b {
			a, b = b, a
		}
		count[a] += 1
		count[b] += 1
		repeat[tuple{a, b}] += 1
	}
	ans := 0
	for k, v := range repeat {
		if count[k.a]+count[k.b] >= p && count[k.a]+count[k.b]-v < p {
			ans -= 1
		}
	}

	sort.Ints(count)
	l := 0
	for r := n - 1; r > -1; r -= 1 {
		for l < r && count[l]+count[r] < p {
			l += 1
		}
		if l == r {
			break
		}
		ans += r - l // 对于当前右端点，有r-l个左端点相加可以大于等于p
	}
	fmt.Fprintf(out, "%d", ans)
}
