package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strings"
)

// 1的个数只能相等或者相加为n + 1
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	var a, b string
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &a, &b)
	if a == b {
		fmt.Fprintln(out, 0)
		return
	}
	o1 := strings.Count(a, "1")
	o2 := strings.Count(b, "1")
	if o1 == 0 {
		fmt.Fprintln(out, -1)
		return
	}
	if o1 != o2 && 1+n-o1 != o2 {
		fmt.Fprintln(out, -1)
		return
	}
	ans := math.MaxInt64
	cur := 0
	for i := 0; i < n; i++ {
		if a[i] != b[i] {
			cur++
		}
	}
	if o1 == o2 {
		ans = min(ans, cur)
	}
	if 1+n-o1 == o2 {
		ans = min(ans, n-cur)
	}
	fmt.Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
