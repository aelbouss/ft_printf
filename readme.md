# ft_printf

Printing formatted output is something every developer relies on daily. At 42, we take away the real `printf` from `<stdio.h>` and write our own version using variadic arguments in C.

**ft_printf** is about learning how a function can take an unknown number of parameters, parsing a format string on the fly, and converting data types into characters printed to standard output.

---

## Overview

The function signature matches the original:

```c
int ft_printf(const char *format, ...);

```

Like the standard library function, it walks through the format string character by character. When it hits a `%`, it inspects the next character to determine the argument type, formats it, prints it, and returns the total number of characters printed.

---

## Supported Conversions

| Specifier | Description | Example Input | Example Output |
| --- | --- | --- | --- |
| `%c` | Single character | `'A'` | `A` |
| `%s` | String of characters | `"42 Network"` | `42 Network` |
| `%p` | Memory address (hexadecimal) | `&var` | `0x7ffee3b4a2` |
| `%d` / `%i` | Signed decimal integer | `-42` | `-42` |
| `%u` | Unsigned decimal integer | `3000000000` | `3000000000` |
| `%x` | Hexadecimal integer (lowercase) | `255` | `ff` |
| `%X` | Hexadecimal integer (uppercase) | `255` | `FF` |
| `%%` | Literal percent sign | None | `%` |

---

## How It Works

1. **Variadic List Setup:** Uses `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) to walk through the argument list without knowing in advance how many parameters were passed.
2. **String Traversal:** Loops through the format string:
* Regular characters get written directly to standard output (`write(1, ...)`).
* Encountering `%` routes execution to a dispatcher function that handles the conversion specifier.


3. **Data Conversion & Base Switching:**
* Numbers (`%d`, `%i`, `%u`) are converted to ASCII strings using recursion or an iterative division loop.
* Pointers and hex values (`%p`, `%x`, `%X`) use base-16 modulo arithmetic.


4. **Byte Counting:** Every single printed character increments a shared counter. The function returns this counter at the end, exactly mimicking `printf`'s return value.

---

## Getting Started

### 1. Compile the Library

```bash
git clone https://github.com/aelbouss/ft_printf.git
cd ft_printf
make

```

This generates `libftprintf.a`.

### 2. Basic Usage

Include the header in your C file:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Score: %d, Hex: %x, Ptr: %p\n", "User", 42, 255, &count);
    ft_printf("Printed %d characters.\n", count);
    return (0);
}

```

Compile with the library archive:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
./test_printf

```

