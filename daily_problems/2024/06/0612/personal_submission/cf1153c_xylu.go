package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveC(os.Stdin, os.Stdout) }

func solveC(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	n, s := readNum(in), readString(in)
	if n&1 == 1 {
		fmt.Fprintln(out, ":(")
		return
	}

	b := []byte(s)
	cntL, cntR := n/2, n/2
	for _, c := range b {
		if c == '(' {
			cntL--
		} else if c == ')' {
			cntR--
		}
	}

	if cntL < 0 || cntR < 0 {
		fmt.Fprintln(out, ":(")
		return
	}

	t := 0
	for i := n - 1; i >= 0; i-- {
		if b[i] == '?' {
			if cntR > 0 {
				b[i], cntR = ')', cntR-1
			} else {
				b[i], cntL = '(', cntL-1
			}
		}

		if b[i] == '(' {
			t--
		} else {
			t++
		}

		if i > 0 && t <= 0 {
			fmt.Fprintln(out, ":(")
			return
		}
	}

	fmt.Fprintln(out, string(b))
}
