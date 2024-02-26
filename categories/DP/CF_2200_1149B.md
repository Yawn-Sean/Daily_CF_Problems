<center>

### B. Three Religions

time limit per test: 3 seconds

memory limit per test: 256 megabytes

input: standard input

output: standard output

</center>

During the archaeological research in the Middle East you found the traces of three ancient religions: First religion, Second religion and Third religion. You compiled the information on the evolution of each of these beliefs, and you now wonder if the followers of each religion could coexist in peace.

The Word of Universe is a long word containing the lowercase English characters only. At each moment of time, each of the religion beliefs could be described by a word consisting of lowercase English characters.

The three religions can coexist in peace if their descriptions form disjoint subsequences of the Word of Universe. More formally, one can paint some of the characters of the Word of Universe in three colors: $1$, $2$, $3$, so that each character is painted in at most one color, and the description of the $i$\-th religion can be constructed from the Word of Universe by removing all characters that aren't painted in color $i$.

The religions however evolve. In the beginning, each religion description is empty. Every once in a while, either a character is appended to the end of the description of a single religion, or the last character is dropped from the description. After each change, determine if the religions could coexist in peace.

**Input**

The first line of the input contains two integers $n, q$ ($1 \leq n \leq 100\,000$, $1 \leq q \leq 1000$) — the length of the Word of Universe and the number of religion evolutions, respectively. The following line contains the Word of Universe — a string of length $n$ consisting of lowercase English characters.

Each of the following line describes a single evolution and is in one of the following formats:

-   + $i$ $c$ ($i \in \{1, 2, 3\}$, $c \in \{\mathtt{a}, \mathtt{b}, \dots, \mathtt{z}\}$: append the character $c$ to the end of $i$\-th religion description.
-   \- $i$ ($i \in \{1, 2, 3\}$) – remove the last character from the $i$\-th religion description. You can assume that the pattern is non-empty.

You can assume that no religion will have description longer than $250$ characters.

**Output**

Write $q$ lines. The $i$\-th of them should be YES if the religions could coexist in peace after the $i$\-th evolution, or NO otherwise.

You can print each character in any case (either upper or lower).