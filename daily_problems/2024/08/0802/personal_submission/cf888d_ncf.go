package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF888D(os.Stdin, os.Stdout) }

func CF888D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, k int
	fmt.Fscan(in, &n, &k)
	ans := 1
	v := 1
	for i := 1; i <= k; i++ {
		v = v * (n - i + 1) / i
		if i == 2 {
			ans += v
		}
		if i == 3 {
			ans += v * 2
		}
		if i == 4 {
			ans += v * 9
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
}
