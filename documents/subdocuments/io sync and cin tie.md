### ios::sync_with_stdio(false);

By default, C++ standard I/O streams (cin, cout, cerr, etc.) are synchronized with C standard I/O streams (scanf, printf, stderr).
"In practice, this means that the synchronized C++ streams are unbuffered, and each I/O operation on a C++ stream is immediately
 applied to the corresponding C stream's buffer.
 This makes it possible to freely mix C++ and C I/O."

ios::sync_with_stdio(false) is used to disconnect the C++ streams from the C streams.
Disabling synchronization may cause issues with mixing C and C++ I/O functions (e.g., using both cout and printf).

```cpp
int main() {
    std::ios::sync_with_stdio(false); // Disable synchronization between iostream and stdio

    // Intermixing cout and printf
    std::cout << "from cout.\n";
    printf("from printf.\n");

    std::cout << "Another cout.\n";
    printf("Another printf.\n");

    return 0;
}
```

Possible (unexpected) Output:

from printf.  
from cout.  
Another cout.  
Another printf.

In practice, this means that if you don't want to get TimeLimmitExited, you will only use C or C++ I/O functions.

---

### cin.tie(nullptr);

By default, std::cin is tied to std::cout, it ensures that if any characters are pending for output, the output buffer is flushed before any input operation is performed.  
This flushing is unnecessary overhead.

cin.tie(nullptr) is used to untie cin from cout.

This can lead to unexpected output when your program relies on cout to flush automatically before a cin operation

```cpp
int main() {
    std::cin.tie(nullptr); // Untie cin from cout

    std::cout << "Please enter your name: ";
    // Notice that we're not flushing cout manually with std::endl or std::flush

    std::string name;
    std::cin >> name; // Input operation

    std::cout << "Hello, " << name << "!\n";

    return 0;
}
```

In a typical console application, you would expect the prompt "Please enter your name: " to appear and then wait for the user to input their name.  
However, due to cin.tie(nullptr), cout may not automatically flush its buffer before the program pauses to wait for input from cin. As a result,
the prompt might not appear on the screen until after you've entered your name and pressed Enter, or it might appear right before the output without giving you a clear indication when to input.

The online judges give you all the input immediately so we can safely use cin.tie(nullptr),  
this will only impact performance if you use cin and cout interchangeably.