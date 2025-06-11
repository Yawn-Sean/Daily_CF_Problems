package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF570C(os.Stdin, os.Stdout) }

func CF570C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, x int
	var s, c string
	fmt.Fscan(in, &n, &m, &s)
	a := make([]uint8, n)
	ans := 0
	for i := 0; i < n; i++ {
		a[i] = s[i]
		if i > 0 && a[i] == '.' && a[i-1] == '.' {
			ans++
		}
	}
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &x, &c)
		x--
		if a[x] == '.' {
			if c[0] != '.' {
				if x > 0 && a[x-1] == '.' {
					ans--
				}
				if x < n-1 && a[x+1] == '.' {
					ans--
				}
			}
		} else if c[0] == '.' {
			if x > 0 && a[x-1] == '.' {
				ans++
			}
			if x < n-1 && a[x+1] == '.' {
				ans++
			}
		}
		a[x] = c[0]
		fmt.Fprintf(out, "%d\n", ans)
	}
}
