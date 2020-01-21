#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <cctype>

// this is a "functor", a class that implements the operator () and can
// therefore be called in a function-like way
class frequency_counter {
  // we don't have unordered_map yet, only the good old map with O(log n)
  std::map<std::string, int>* map;
  std::string current_word;

  public:
  frequency_counter(std::map<std::string, int>* m) : map(m), current_word() {}
  void operator()(const char letter) {
    // in case it is a alpha character
    if (isalpha(letter)) {
      // convert to lower case
      current_word += tolower(letter);
    } else {
      // if there is a word built
      if (current_word.size() > 0) {
        // increment mapping for current word
        (*map)[current_word]++;
        // reset our buffer
        current_word = "";
      }
    }
  }
};

int main() {
  std::map<std::string, int> map;
  frequency_counter functor(&map);
  
  // word counting using for_each and the frequency_counter functor
  std::for_each(std::istream_iterator<char>(std::cin >> std::noskipws),
                std::istream_iterator<char>(),
                functor);

  // old way to iterate over a collection
  for (std::map<std::string, int>::iterator it = map.begin();
       it != map.end();
       ++it)
    std::cout << it->first << ": " << it->second << std::endl;

  return 0;
}
