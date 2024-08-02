package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

// 从1 1x 1xx 1xxx 1xxx... 里面每组选一个或者不选构成序列
func solve(in *bufio.Reader, out *bufio.Writer) {
	var d, m int
	fmt.Fscan(in, &d, &m)
	ans := 1
	high := bits.Len(uint(d)) - 1
	for i := 0; i <= min(high, 30); i++ {
		if i < high {
			ans = (ans * ((1 << i) + 1)) % m
		} else {
			ans = ans * (d - (1 << i) + 2) % m
		}
	}
	ans = (ans - 1 + m) % m
	fmt.Fprintln(out, ans)
}
func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		solve(in, out)
	}
}
