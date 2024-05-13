package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solve(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var a, b, c, d int
	fmt.Fscan(in, &a, &b, &c, &d)
	ans := make([][]byte, 50)
	for i := range ans {
		ans[i] = make([]byte, 50)
	}
	for i := 0; i < 25; i++ {
		for j := 0; j < 25; j++ {
			ans[i][j] = 'A'
			ans[i][j+25] = 'B'
			ans[i+25][j] = 'C'
			ans[i+25][j+25] = 'D'
		}
	}
	fill := func(x, y, cnt int, ch byte) {
		for i := 1; i < 25; i += 2 {
			for j := 1; j < 25; j += 2 {
				if cnt == 0 {
					return
				}
				ans[x+i][y+j] = ch
				cnt--
			}
		}
	}
	fill(0, 0, d-1, 'D')
	fill(0, 25, a-1, 'A')
	fill(25, 0, b-1, 'B')
	fill(25, 25, c-1, 'C')
	fmt.Fprintln(out, 50, 50)
	for i := range ans {
		fmt.Fprintln(out, string(ans[i]))
	}
}

func main() {
	solve(os.Stdin, os.Stdout)
}
