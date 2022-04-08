#include "noise.h"
#include <iostream>
#include <concepts>

template<typename T, typename ... U>
concept IsAnyOf = (std::same_as<T, U> || ...);
 
template<typename T>
concept IsPrintable = std::integral<T> || std::floating_point<T> ||
    IsAnyOf<std::remove_cvref_t<std::remove_pointer_t<std::decay_t<T>>>, char, wchar_t>;
 
void println(IsPrintable auto const ... arguments)
{
    (std::wcout << ... << arguments) << '\n';
}

void test() {
    std::cout << "hello noise." << std::endl;
}