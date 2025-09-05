# Csquare (C²)

**Csquare (C²)** is a super-hybrid programming toolkit that makes **C as simple as Scratch**, as **readable as Python**, and still as **blazingly fast and minimal as C/ASM**.  

It is not a new language, but a **smart header-only library (`csquare.h`)** that extends plain C with Scratch-like macros, Python-like syntax sugar, and optional inline ASM for ultimate performance.

---

## ✨ Features

- 🔹 **Scratch-like simplicity**  
  Use macros like `repeat(n) { … }`, `forever { … }` to code like Scratch.

- 🔹 **C-level speed**  
  Compiles down to **pure C**, no interpreter, no VM. Efficient and lightweight.

- 🔹 **Python readability**  
  Syntax feels like pseudocode. Great for beginners and rapid prototyping.

- 🔹 **Hybrid control**  
  Mix high-level macros with normal C whenever you need.  
  Drop to inline ASM for performance-critical code.

- 🔹 **Raylib integration**  
  (Optional) `smotion.h` wrapper brings Scratch-style motion & graphics using Raylib.

---

## 🖥️ Example Code

```c
#include "csquare.h"

int main() {
    repeat(5) {
        say("Hello World!");
        wait(1);
    }
    say("Hello world has been said 5 times!");
}
```
## 🔑 License
MIT License

Copyright (c) 2025 dev-sudeep

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
