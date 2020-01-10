---
layout: post
title:  "Quick tour from C++98 to C++17"
author: carlos
categories: [ programming, tutorial ]
image: assets/images/11.jpg
tags: [ sticky, featured ]
---
Wait, no more `new`? Wtf is `auto`? `constexpr`?! Why so many keywords?? Dafuq do they do?!
What the hell happened with C++ since college?


## The good old days of C++98

So, what nobody told me is this, the C++ is an International Standard, and as such, it evolves (gradually and upon many discussions).
What we learn in college is actually a set of rules stablished by the ISO revision of 98 in which we have destructors, templates,
our beloved STL with common containers and algorithms, string, I/O streams, among other things. However, **C++ is NOT static**
and major changes happened since then, some of them can make you feel it's not even the same language anymore.

If you are like me and started programming in other languages to follow the market flow and now you are trying
to code in C++ again, for fun or business, you may have a hard time with the new concepts that arrived to the language since then,
let me try to make it easier for you, putting together the information I found useful during my research.

## So, what's changed?

Well... ~~a lot! Kidding, but not kidding~~ Breaking the main changes into pieces makes it easier to follow along,
so in the next sections I'm gonna try to illustrate how the same code would be written in different C++ revisions
introducing the main features of each one.

### C++03

This realease is commonly known as a bug fix release for the C++98 revision and included only one new feature, 
[value initialization](https://en.cppreference.com/w/cpp/language/value_initialization).

### C++11

- auto
- ranged for loops
- lambdas
- variadic templates
- unique_ptr/shared_ptr
- constexpr

### C++14

Generally speaking, enhancements in the C++11
- auto in function return types
- generic lambda functions
- make_unique/make_shared (new or delete should not be seen in code anymore)
- constexpr more flexible

### C++17

- constexpr support in stdlib
- constexpr lambdas
- std::string_view
- class template argument deduction
- fold expressions
- structured bindings
- if-init expressions

```
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[])
{
  unordered_map<string, int> umap;

  for_each(argv + 1, argv + argc, [&umap](char *x) {umap[x]++;});

  for (auto &[first, second] : umap)
    cout << first << ", " << second << endl;

  return 0;
}
```

### EXTRA: C++20

Future (Feb, 2020), introduces modules, coroutines, std::format, among others.


#### References, credits and things you may want to check out

- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Current Status](https://isocpp.org/std/status)
- [The Next Big Thing: C++20](https://www.modernescpp.com/index.php/c-20-an-overview)
- [C++ Weekly - Ep 176 - Important Parts of C++11 in 12 Minutes](https://www.youtube.com/watch?v=D5n6xMUKU3A)
- [C++ Weekly - Ep 178 - The Important Parts of C++14 In 9 Minutes](https://www.youtube.com/watch?v=mXxNvaEdNHI)
- [C++ Weekly - Ep 190 - The Important Parts of C++17 in 10 Minutes](https://www.youtube.com/watch?v=QpFjOlzg1r4)

Topics
- c++ is an international standard
- highlight changes per standard
- c++ timeline image
- introduce new features briefly: shared_ptr, unique_ptr, auto, cosntexpr, decltype, lamba functions...
- code examples


