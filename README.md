# bstCalc
<img src="https://img.shields.io/badge/c-064F8C?style=for-the-badge&logo=c&logoColor=white">

**2024년 창원대학교 컴퓨터공학과 자료구조 과제**

A simple Infix expression evaluator using a binary tree.

**Compatibility checked on:**
|Compiler|Target|OS|Checked|
|-|-|-|:-:|
|GCC 11.4.0|x86_64-linux-gnu|Ubuntu Server 22.04.4 LTS|✅|
|Apple clang 15.0.0|arm64-apple-darwin23.5.0|macOS Sonoma 14.5|✅|
|Microsoft Visual C++ 1936|x86_64|Windows 11 Enterprise x64|✅|
|GCC 13.2.0|x86_64-w64-mingw32|Windows 11 Enterprise x64|✅|

**TODO:** Max value of calculation is limited by INT32_MAX. result will overflow if result is exceeds boundary.


### Table of Content
- [Features](#features)
- [Showcase](#showcase)

## Features
**Updated on 6/10/2024: No more use of stack and postfix expression.**
- Parse infix expression (Support positive multi-digit numbers).
- Extendable operators (Singleton-like).
- ~~Infix -> postfix conversion.~~
- Infix -> expression tree conversion.
- ~~Postfix evaluation using binary tree.~~
- Expression tree evaluation.
  
## Showcase
```bash
coppermine@labserver:~/bstCalc/src$ ./bstcalc
>> 1+1+2-3
result: 1

>> 16/2/2
result: 4

>> 1+2 * (3 -5) * 6
result: -23

>> 16/(2/2)
result: 16

>> 2^3
result: 8

>> 1 + (2*5 - 4
Input Error

>> [Enter]
coppermine@labserver:~/bstCalc/src$
```
