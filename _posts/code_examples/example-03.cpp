#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
// regex in tr1 was never fully functional
#include <tr1/regex>

struct frequency_counter {
  std::tr1::unordered_map<std::string, int>* map;

  frequency_counter(std::tr1::unordered_map<std::string, int>* m) : map(m) {}
  void operator()(const char* word) {
    (*map)[word]++;
  }

};

int main (int argc, char* argv[]) {
  std::tr1::unordered_map<std::string, int> map;
  frequency_counter functor(&map);

  std::for_each(argv + 1, argv + argc, functor);

  for (std::tr1::unordered_map<std::string, int>::iterator it = map.begin();
       it != map.end();
       ++it)
    std::cout << it->first << ": " << it->second << std::endl;

  return 0;
}

