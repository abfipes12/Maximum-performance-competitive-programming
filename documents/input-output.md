
### ios::sync_with_stdio(false) and cin.tie(nullptr)

TL;TR;

cin/cout is now 100 times faster if you stated  
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```
before I/O operations, but you can no longer mix C and C++ I/O functions.

[read more](subdocuments/io%20sync%20and%20cin%20tie.md)

#### cout.tie(nullptr) ???

By default, cout is not tied to anything, so this statement is unnecessary.

---

### endl vs '\n'

'\n' is better because unlike endl it doesn't do an expensive flush.

---

### cin after optimizations vs scanf

cin and cout are [a little faster] (link) than their C counterparts, scanf and printf.  
printf and scanf interpret the format string to know how to handle its arguments.  
cin and cout use templates and know what function to use at compile time.

---

### getchar vs getchar_unlocked

getchar_unlocked, putc_unlocked putchar_unlocked are functionally identical to the original versions, except that they do not have to be implemented in a thread-safe manner.

This makes getchar_unlocked ??? faster than getchar,
and putchar_unlocked ??? faster than putchar.

The "unlocked" features are not standard C++, but are available on Linux systems.
On Windows®™, try _getchar_nolock and _putchar_nolock.

---

### Custom I/O

We can take advantage of the fact that our input will have many constraints that we know in advance.

Some Fast I/O™ function propositions:

```cpp
// about ??? faster than cin (link)
int get_uint()
{
    int x{};
    auto &gu{getchar_unlocked};
    for (int c = gu(); c >= '0'; c = gu())
        x = x * 10 + c - '0';

    return x;
}
```

We don't need to check if c <= '9' because ' ', '\n' and EOF are <= '9'.

[more functions](../templates%20and%20examples/input-output.cpp)

---

### fread_unlocked

If we want, we can manage the buffers ourselves.

```cpp
char buf[200'000];
fread_unlocked(&buf, sizeof(char), n, stdin);
```

TODO