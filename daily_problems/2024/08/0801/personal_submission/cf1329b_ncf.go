package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1329B(os.Stdin, os.Stdout) }

func CF1329B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, d, m int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &d, &m)
		ans := 1 % m
		i := 2
		shift := 0
		for i <= d {
			next := i << 1
			if next <= d {
				ans = (ans + (ans+1)*i) % m
			} else {
				ans = (ans + (ans+1)*(d-i+1)) % m
			}
			i = next
			shift++
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
