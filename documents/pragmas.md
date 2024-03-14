
In competitive programming, participants often use specific compiler directives, called pragmas, to optimize the performance of their code or to instruct the compiler to behave in a certain way. These directives are non-standard but supported by many compilers, offering various optimizations and functionalities.

[codeforces blog which covers most of the topic.](https://codeforces.com/blog/entry/96344) (recomended read)  

[gentoo wiki "GCC_optimization"](https://wiki.gentoo.org/wiki/GCC_optimization)

[gcc documentation](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)

---

### #pragma GCC optimize

-O2 is the default setting for most online judges.  
-O3 is considered safe if you do not rely on UB; e.g. signed integer overflow.  
-Ofast breaks floats quite often and mainly focuses on float operations.

ipa-pta - "interprocedural pointer analysis ..." is disabled on every optimization level because is very compile-time expensive.

unroll-loops - "Unroll loops [...] makes code larger, and may or may not make it run faster."

Some recommended flags:  
```#pragma GCC optimize("O3,unroll-loops,ipa-pta")```

---

### #pragma GCC target

[gcc documentation](https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html)

If you want your target pragma to work on every judge  
```#pragma GCC target("tune=native")```

tune=native - "produces code optimized for the local machine under the constraints of the selected instruction set." It won't give any new instructions for gcc to use, but will do some CPU specific tuning.

boost SIMD avx2 introduced on Haskell Intel processors (June 2013).  
```#pragma GCC target("avx2")```

avx2 - superset of avx is super set of sse allow us to utilize new big register for simultaneous operations on data (SIMD)

#pragma GCC target("arch=native") would specify all available instructions and allow g++ to use them.  
Unfortunately, it doesn't work.

We can still set the arch flag, but we need to specify what processor microarchitecture we expect.  
For example, if our judge is running on some Intel Alderlake (2021) processor or other processor that has a superset of these instructions available, we can use  
```#pragma GCC target("tune=native,arch=alderlake")```

---

### A non-comprehensive list of pragmas for what I hope are popular Intel architectures

(2010)
#pragma GCC target("tune=native,arch=westmere")

(2013)
#pragma GCC target("tune=native,arch=haswell")

(2015)
#pragma GCC target("tune=native,arch=skylake")

[intel not doing much for 5 years](https://en.wikipedia.org/wiki/List_of_Intel_CPU_microarchitectures)

(2020)
#pragma GCC target("tune=native,arch=tigerlake")

(2021)
#pragma GCC target("tune=native,arch=alderlake")

---

### Disclaimer

I've heard that some judges disallow pragmas; I don't know any, but I haven't read any rules either.

---

#### Other [honorable flags](subdocuments/more%20pragmas.md)
