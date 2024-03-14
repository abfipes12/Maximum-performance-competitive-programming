
### int vs. unsigned int

It depends on the processor, it also depends on the operation to be performed.

[instruction_tables.pdf](https://www.agner.org/optimize/instruction_tables.pdf)

let's check the some Skylake timings

| instruction | size | time | 
| ---- | --- | -- |
| MUL  | r32 | 3  |
| IMUL | r32 | 3  |
| MUL  | r64 | 2  |
| IMUL | r64 | 2  |
| DIV  | r32 | 10 |
| IDIV | r32 | 10 |
| DIV  | r64 | 36 |
| IDIV | r64 | 57 |

There is no signed addition or subtraction thanks to the two-complement representation of negative numbers.

Some older processors have slower signed than unsigned 32-bit divisions.Remember that dividing (and modulo) by a constant is optimized and does not require division.

so unsigned are clearly better, right?

Not entirely, there is one main advantage of the signed, i.e. undefined behavior - **Signed overflow is UB.** The compiler can optimize signed more aggressively. If only there was some way to allow unsigned UB overflow, then unsigned would certainly be faster than signed, but that's not the case.

rule of thumb

- signed for everything
- unsigned for long division by non compile-time constant

---

### What are int_fasts?

https://en.cppreference.com/w/cpp/types/integer

int_fast##_t - "fastest signed integer type with width of at least 8, 16, 32 and 64 bits respectively"

from [The GNU C Library (glibc) stdint.h](https://github.com/gcc-mirror/gcc/blob/master/gcc/config/glibc-stdint.h), int_fast32_t is:

- 64-bit integer (on 64bit processors)  
- 32-bit integer (on 32bit processors)

[more accurately](https://www.gnu.org/software/libc/manual/html_node/Integers.html) - "fastest access while having at least N bits (and among data structures with the same access speed, the smallest one)"

---

### short vs. int vs. long

let's check the some Skylake timings

| instruction | size | time | 
| ---- | --- | -- |
| MUL  | r8  | 1  |
| MUL  | r16 | 4  |
| MUL  | r32 | 3  |
| MUL  | r64 | 2  |

before you replace all ints with longs, note that processors have a finite number of registers and a limited cache, also g++ is quite smart. There's nothing stopping g++ from using 64-bit registers for smaller types.

Conclusion:  
int

---

### Constness

#### constexpr vs const

check [Alex's tutorial](https://www.learncpp.com/cpp-tutorial/constexpr-variables/)

you may enjoy [this Jason Turner's experiment](https://twitter.com/lefticus/status/1002235029429239809?lang=en), if you play with that, you may notice that unlike g++, clang is quite lazy. but [g++ can be lazy too](https://gcc.godbolt.org/z/ddKbvbK7E)

compilers are smart enough to know if a variable changes its contents or is known at compile time.

compilers dont want you to wait too long for executable and const nor constexpr do not enforce compile-time evaluation.

for expensive (but not too expensive) computations, consteval (or finding answer manualy) is probably what are we looking for.

const is still a very useful keyword in C++, but it probably won't give us much performance.

---

### Reference vs. pointer

In some situations, the reference may be faster.

TODO