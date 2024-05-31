package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	solveD(os.Stdin, os.Stdout)
}

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var T, n, x int
	for fmt.Fscan(in, &T); T > 0; T-- {
		fmt.Fscan(in, &n, &x)
		a := make([]int, n)
		ans, mn, mx := 0, 1_000_000, 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			mn = min(a[i], mn)
			mx = max(a[i], mx)
		}
		// [mn, mx] 之间的数均可无额外代价填好
		for i := 1; i < n; i++ {
			ans += abs(a[i] - a[i-1])
		}
		// 小于 mn 的数，填在 mn 两边，增加代价为 ((mn - 1) + ((mn + 1) - 1)) - 1
		// 填在两侧，增加代价为 min(a[0], a[n-1]) - 1
		if mn > 1 {
			ans += min(2*mn-2, a[0]-1, a[n-1]-1)
		}
		// 大于 mx 的数，填在 mx 两边，增加代价为 ((x - mx) + (x - (mx - 1))) - 1
		// 填在两侧，增加代价为 x - max(a[0], a[n-1])
		if mx < x {
			ans += min(2*x-2*mx, x-a[0], x-a[n-1])
		}
		fmt.Fprintln(out, ans)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
