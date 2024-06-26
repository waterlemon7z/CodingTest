# [Silver V] Cyclical Periods - 30545 

[문제 링크](https://www.acmicpc.net/problem/30545) 

### 성능 요약

메모리: 2024 KB, 시간: 8 ms

### 분류

구현

### 제출 일자

2024년 1월 20일 14:52:29

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 644px; height: 50px;"></p>

<p>The image illustrates the superposition of four cycles $a$, $b$, $c$, and $d$ of differing offsets and periods. It can be quickly seen that $a$ appears every 3 steps with an offset of 3, $b$ every 4 steps with an offset of 2, $c$ every 7 steps with an offset of 5, and $d$ every 11 steps with an offset of 4. Cycle $d$ can be seen to have the longest period. The first sample input describes the case in the image.</p>

<p>Given a sequence of strings of lowercase letters (arbitrary ordering of letters in each string) and their positions on the number line, your task is to determine which letter represents the cycle with the longest period.  The number line will start at 1 and will not be longer than $65{,}536$.  Any letter that appears will appear at least twice, and it will appear on the entire number line at locations consistent with its offset and period.</p>

### 입력 

 <p>The first line contains an integer $N$ ($2 \leq N \leq 65{,}536$), representing the number of strings on the number line.  Each subsequent line describes a position on the number line that has at least one letter associated with it.  Each description line begins with a positive integer $P$ ($1 \leq P \leq 65{,}536$) representing the position on the number line followed by a space, and then the string of lowercase letters associated with this position.  No letters will be repeated within a string, and the positions are strictly increasing from one line to the next.  </p>

### 출력 

 <p>Print the single letter that represents the longest cycle length. In case of a tie, use the cycle that appears at the earliest position.  If there is still a tie, use the letter that appears first in the string when the cycle is first discovered.</p>

