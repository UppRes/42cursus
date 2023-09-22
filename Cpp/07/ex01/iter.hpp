#pragma once

#include <iostream>

template <typename Type>
void iter(Type *ptr, size_t len, void (*func)(Type &))
{
    size_t i = -1;

    while (++i < len)
        func(ptr[i]);
}
