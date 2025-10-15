package main

import (
	"bufio"
	"fmt"
	"os"
)

const mod = 1e9 + 7

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, q int
	fmt.Fscan(in, &n, &q)
	var str string
	fmt.Fscan(in, &str)
	mi := make([]int, n+1)
	mi[0] = 1
	for i := 1; i <= n; i++ {
		mi[i] = mi[i-1] * 2 % mod
	}
	cnt := make([]int, n+1)
	for i := 1; i <= n; i++ {
		cnt[i] = cnt[i-1]
		if str[i-1] == '1' {
			cnt[i]++
		}
	}
	for i := 0; i < q; i++ {
		var l, r int
		fmt.Fscan(in, &l, &r)
		l--
		one := cnt[r] - cnt[l]
		len := r - l
		ans := mi[len-one] * (mi[one] - 1) % mod
		fmt.Fprintln(out, ans)
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
