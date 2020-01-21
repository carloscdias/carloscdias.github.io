---
layout: post
title:  "Quick tour from C++98 to C++17"
author: carlos
categories: [ programming, tutorial ]
image: assets/images/11.jpg
tags: [ sticky, featured ]
---
Wait, no more `new`? Wtf is `auto`? `constexpr`?! Why so many keywords??
What the hell happened with C++ since college?


## The good old days of C++98

So, what nobody told me is this, the C++ is an International Standard, and as such, it evolves (gradually and upon many discussions).
What we learn in college is actually a set of rules stablished by the ISO revision of 98 in which we have destructors, templates,
our beloved STL with common containers and algorithms, string, I/O streams, among other things. However, **C++ is NOT static**
and major changes happened since then, some of them can make you feel it's not even the same language anymore.

If you are like me and started programming in other languages to follow the tides of the market and now you are trying
to code in C++ again, for fun or business, you may have a hard time with the new concepts that arrived to the language,
let me try to make it easier for you, putting together the information I found useful during my research.

## So, what's changed?

Well... ~~a lot! Kidding, but not kidding~~ Let's break the main changes into pieces and follow along with a simple sample code,
so in the next sections I'm gonna try to illustrate how the same code would be written in different C++ revisions
introducing the main features of each one.

Our sample code will be a program that reads input from the standard input and outputs a map of word frequency,
ignoring any non-alphabetic character and, by convenience, transforming all characters to lower case.

In C++98 it would look like this:

{% highlight cpp %}
{% include_relative code_examples/example-98.cpp %}
{% endhighlight %}

Fairly simple, right? Moving on...

### C++03

This realease is commonly known as a bug fix release for the C++98 revision and included only one new feature, 
[value initialization](https://en.cppreference.com/w/cpp/language/value_initialization), as a side note, when most people refer to
C++98 they are usually refering to C++03.

One valuable addition to the language came in the form of [Technical Report 1](https://en.wikipedia.org/wiki/C%2B%2B_Technical_Report_1) (TR1 for short) around 2005.
TR1 is not a standard...

{% highlight cpp %}
{% endhighlight %}

### C++11

- auto
- ranged for loops
- lambdas
- variadic templates
- unique_ptr/shared_ptr
- constexpr

{% highlight cpp %}
{% include_relative code_examples/example-11.cpp %}
{% endhighlight %}

### C++14

Generally speaking, enhancements in the C++11
- auto in function return types
- generic lambda functions
- make_unique/make_shared (new or delete should not be seen in code anymore)
- constexpr more flexible

{% highlight cpp %}
{% include_relative code_examples/example-14.cpp %}
{% endhighlight %}

### C++17

- constexpr support in stdlib
- constexpr lambdas
- std::string_view
- class template argument deduction
- fold expressions
- structured bindings
- if-init expressions

{% highlight cpp %}
{% include_relative code_examples/example-17.cpp %}
{% endhighlight %}

### EXTRA: C++20

Future (Feb, 2020), introduces modules, coroutines, std::format, among others.
Coroutines, Modules, Concepts, abbreviated function templates, Ranges, uniform container erasure (std::erase/std::erase_if).


#### References, credits and things you may want to check out

- [C++ History](https://en.cppreference.com/w/cpp/language/history)
- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Current Status](https://isocpp.org/std/status)
- [The Next Big Thing: C++20](https://www.modernescpp.com/index.php/c-20-an-overview)
- [C++ Weekly - Ep 176 - Important Parts of C++11 in 12 Minutes](https://www.youtube.com/watch?v=D5n6xMUKU3A)
- [C++ Weekly - Ep 178 - The Important Parts of C++14 In 9 Minutes](https://www.youtube.com/watch?v=mXxNvaEdNHI)
- [C++ Weekly - Ep 190 - The Important Parts of C++17 in 10 Minutes](https://www.youtube.com/watch?v=QpFjOlzg1r4)

