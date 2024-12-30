package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

func solveB(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n, &m)
	ans := 0
	for i := 1; i <= m; i++ {
		for j := 1; j <= m; j++ {
			if (i*i+j*j)%m == 0 {
				ans += (n - i + m) / m * ((n - j + m) / m)
			}
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveB(os.Stdin, os.Stdout)
}
