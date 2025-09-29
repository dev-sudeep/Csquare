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

- 🔹 **PyGame grphics integration**  
  (Optional) `smotion.h` wrapper brings Scratch-style motion & graphics using the power of InPy and the PyGame library

---

## 🖥️ Example Code

```c
#include <csquare.h>
int main(){
    repeat(5, __i) {
        say("Hello, world! %d repeat\n", __i + 1);
        wait(1);
    }
    say("Hello world has been said 5 times!\n");
    char* result = inpy("print(2 + 2)");
    say("2 + 2 = %s\n", result);
    say("InPy says 2 + 2 = %s\n", result);
    
    say("Starting Pygame window...\n");
    sm_init();
    wait(0.5); // Increased delay for initialization
    
    say("Drawing shapes...\n");
    
    // Draw multiple shapes
    sm_draw("circle", "(255, 0, 0), (400, 300), 50");  // Red circle
    sm_draw("rect", "(0, 255, 0), pygame.Rect(200, 200, 100, 100)");  // Green square
    sm_draw("line", "(0, 0, 255), (100, 100), (700, 500), 5");  // Blue line with thickness 5
    
    // Keep window open
    say("Shapes drawn. Window will close in 10 seconds...\n");
    wait(10);
    
    sm_quit();
    return 0;
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
