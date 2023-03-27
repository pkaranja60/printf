#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
va_list arg;
int count = 0;
va_start(arg, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += putchar(va_arg(arg, int));
break;
case 's':
count += printf("%s", va_arg(arg, char*));
break;
case '%':
count += putchar('%');
break;
case 'd':
case 'i':
count += printf("%d", va_arg(arg, int));
break;
default:
break;
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(arg);
return count;
}
