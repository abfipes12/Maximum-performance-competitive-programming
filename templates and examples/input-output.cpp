
#include <bits/stdc++.h>
using namespace std;

int get_uint()
{
    int x{};
    auto &gu{getchar_unlocked};
    for (int c = gu(); c >= '0'; c = gu())
        x = x * 10 + c - '0';

    return x;
}

// about ??? faster than cout (link)
void put_uint(int x)
{
    static char buf[16];
    char *it = buf;
    do
    {
        *it++ = x % 10 | '0';
    } while (x /= 10);

    while (it != &buf)
        putchar_unlocked(*--it);
}

// TODO https : // github.com/KabukiStarship/KabukiToolkit/wiki/Fastest-Method-to-Print-Integers-and-Floating-point-Numbers

char read_char(){static char b[4194304],*s=b,*e=b;return(s==e&&(s=b)==(e=b+fread_unlocked(b,1,4194304,stdin)))?-1:*s++;}
char read_char()
{
    constexpr int in_size = 4 * 1024 * 1024; // 4 MB
    static char buf[in_size], *beg = buf, *end = buf;

    if (beg == end)
    {
        beg = buf;
        end = buf + fread_unlocked(buf, sizeof(char), in_size, stdin);
        if (beg == end)
            return EOF;
    }
    return *beg++;
}

int get_uint(){int x{};for(char c=read_char();c>='0';c=read_char())x=x*10+c-'0';return x;}
int get_uint()
{
    int x{};
    for (char c = read_char(); c >= '0'; c = read_char())
        x = x * 10 + c - '0';

    return x;
}
