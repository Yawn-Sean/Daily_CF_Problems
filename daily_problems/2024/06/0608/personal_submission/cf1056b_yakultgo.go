package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	cnt := make(map[int]int)
	for i := 1; i <= m; i++ {
		cnt[(i*i)%m] += n / m
	}
	k := n / m * m
	for i := k + 1; i <= n; i++ {
		cnt[(i*i)%m] += 1
	}
	ans := 0
	for i := 0; i < m; i++ {
		ans += cnt[i] * cnt[(m-i)%m]
	}
	fmt.Fprintln(out, ans)
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
