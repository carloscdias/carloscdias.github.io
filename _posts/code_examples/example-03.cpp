#include <iostream>
#include <map>
#include <algorithm>

struct frequency_counter {
  std::map<std::string, int>* map;

  frequency_counter(std::map<std::string, int>* m) : map(m) {}
  void operator()(const char* word) {
    (*map)[word]++;
  }

};

int main (int argc, char *argv[]) {
  std::map<std::string, int> map;
  frequency_counter functor(&map);

  std::for_each(argv + 1, argv + argc, functor);

  for (std::map<std::string, int>::iterator it = map.begin();
       it != map.end();
       ++it)
    std::cout << it->first << ": " << it->second << std::endl;

  return 0;
}
