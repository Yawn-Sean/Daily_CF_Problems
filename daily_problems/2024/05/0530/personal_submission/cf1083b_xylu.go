package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	solveB(os.Stdin, os.Stdout)
}

func solveB(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	var s, t string
	fmt.Fscan(in, &n, &k, &s, &t)
	ans, cnt := 0, 1
	// 遍历长度为i的前缀，cnt为对应方案数
	for i := 0; i < n; i++ {
		cnt = cnt*2 - int(s[i]-'a') - int('b'-t[i])
		if cnt >= k {
			ans += k * (n - i)
			break
		}
		ans += cnt
	}
	fmt.Fprintln(out, ans)
}
