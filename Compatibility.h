#pragma once


// 非 MSVC 编译器下重定义 _s 后缀的函数时还需要忽略多余的参数
#if defined(__GNUC__) || defined(__clang__)
#define UNUSED(expr)                                                                                                                                 \
    do                                                                                                                                               \
    {                                                                                                                                                \
        (void) (expr);                                                                                                                               \
    }                                                                                                                                                \
    while (0)
#else
#define UNUSED(expr) (void) (expr)
#endif // defined(__GNUC__) || defined(__clang__)


// 非 MSVC 编译器下重定义 _s 后缀的函数
#if !defined(_MSC_VER) || defined(__clang__)

#define scanf_s(...) scanf(__VA_ARGS__)
#define strcpy_s(dest, n, src)                                                                                                                       \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        strcpy(dest, src);                                                                                                                           \
    }                                                                                                                                                \
    while (0)
#define strcat_s(dest, n, src)                                                                                                                       \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        strcat(dest, src);                                                                                                                           \
    }                                                                                                                                                \
    while (0)
#define strncpy_s(dest, n, src, m)                                                                                                                   \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        UNUSED(m);                                                                                                                                   \
        strncpy(dest, src, n);                                                                                                                       \
    }                                                                                                                                                \
    while (0)
#define sprintf_s(buf, n, ...)                                                                                                                       \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        sprintf(buf, __VA_ARGS__);                                                                                                                   \
    }                                                                                                                                                \
    while (0)
#define vsprintf_s(buf, n, format, ap)                                                                                                               \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        vsprintf(buf, format, ap);                                                                                                                   \
    }                                                                                                                                                \
    while (0)
#define swscanf_s(...) swscanf(__VA_ARGS__)
#define wcscpy_s(dest, n, src)                                                                                                                       \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        wcscpy(dest, src);                                                                                                                           \
    }                                                                                                                                                \
    while (0)
#define wcscat_s(dest, n, src)                                                                                                                       \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        wcscat(dest, src);                                                                                                                           \
    }                                                                                                                                                \
    while (0)
#define wcsncpy_s(dest, n, src, m)                                                                                                                   \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        UNUSED(m);                                                                                                                                   \
        wcsncpy(dest, src, n);                                                                                                                       \
    }                                                                                                                                                \
    while (0)
#define swprintf_s(buf, n, ...)                                                                                                                      \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        swprintf(buf, __VA_ARGS__);                                                                                                                  \
    }                                                                                                                                                \
    while (0)
#define vswprintf_s(buf, n, format, ap)                                                                                                              \
    do                                                                                                                                               \
    {                                                                                                                                                \
        UNUSED(n);                                                                                                                                   \
        vswprintf(buf, format, ap);                                                                                                                  \
    }                                                                                                                                                \
    while (0)

#endif // !defined(_MSC_VER) || defined(__clang__)
