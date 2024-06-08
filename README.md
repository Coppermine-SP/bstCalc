# bstCalc
<img src="https://img.shields.io/badge/c-064F8C?style=for-the-badge&logo=c&logoColor=white">

**2024년 창원대학교 컴퓨터공학과 자료구조 과제**

A simple Infix expression evaluator using a binary tree.

### Table of Content
- [Features](#features)
- [Showcase](#showcase)

## Features
- Parse infix expression (Support positive multi-digit numbers).
- Extendable operators (Singleton-like).
- Infix -> postfix conversion.
- Postfix evaluation using binary tree.
  
## Showcase
```bash
coppermine@labserver:~/bstCalc/src$ ./bstcalc
>> 1+1+2-3
1 + 1 + 2 - 3
1 1 + 2 + 3 -
result: 1

>> 16/2/2
16 / 2 / 2
16 2 / 2 /
result: 4

>> 1+2 * (3 -5) * 6
1 + 2 * ( 3 - 5 ) * 6
1 2 3 5 - * 6 * +
result: -23

>> 16/(2/2)
16 / ( 2 / 2 )
16 2 2 / /
result: 16

>> 2^3
2 ^ 3
2 3 ^
result: 8

>> 1 + (2*5 - 4
1 + ( 2 * + - 4
1 2 * + 4 - ( +
Input Error

>> [Enter]
coppermine@labserver:~/bstCalc/src$
```
