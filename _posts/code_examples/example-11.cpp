#include <iostream>
#include <unordered_map>
#include <regex>

int main () {
  // unordered_map enters, O(1) achieved \o/
  std::unordered_map<std::string, int> umap;
  // regex become part of the c++ std lib
  std::regex re("[a-z]+");

  // initialize text with stream iterators
  std::string text(std::istream_iterator<char>(std::cin >> std::noskipws),
                   std::istream_iterator<char>());

  // lowercase everything
  std::transform(text.begin(), text.end(), text.begin(),
                 // very lambda
                 [](const unsigned char l){ return std::tolower(l); });

  // find and count words only
  std::for_each(std::sregex_iterator(text.begin(), text.end(), re),
                std::sregex_iterator(),
                // much useful
                [&umap](const std::smatch& match){ umap[match.str()]++; });

  // ordering
  std::vector<std::pair<std::string, int>> freq{umap.begin(), umap.end()};
  std::sort(freq.begin(), freq.end(),
            // many utilities! WOW!
            [](const std::pair<std::string, int>& i, const std::pair<std::string, int>& j){ return i.second > j.second; });

  // print map
  // now we can use auto, specially for variables we don't care
  // like iterating on our frequency map using the ranged for loop
  for (const auto& pair : freq)
    std::cout << pair.first << ": " << pair.second << std::endl;

  return 0;
}
