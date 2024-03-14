
// about ??? faster than cout (link)
void put_uint(int x)
{
    static char buf[16];
    char* it = buf;
    do
    {
        *it++ = x % 10 | '0';
    } while (x /= 10);

    while (it != &buf)
        putchar_unlocked(*--it);
}

TODO  
https://github.com/KabukiStarship/KabukiToolkit/wiki/Fastest-Method-to-Print-Integers-and-Floating-point-Numbers