#include <iostream>
#include <unordered_map>
#include <regex>

template<typename ...Args>
void print_map(Args&&... args) {
  (std::cout << ... << args) << '\n';
}

int main () {
  std::unordered_map<std::string, int> umap;
  std::regex re("[a-z]+");

  // initialize text with stream iterators
  std::string text(std::istream_iterator<char>(std::cin >> std::noskipws),
                   std::istream_iterator<char>());

  // lowercase everything
  std::transform(text.begin(), text.end(), text.begin(),
                 [](const unsigned char l){ return std::tolower(l); });

  // find and count words only
  std::for_each(std::sregex_iterator(text.begin(), text.end(), re),
                std::sregex_iterator(),
                [&umap](const auto& match){ umap[match.str()]++; });

  // ordering
  std::vector<std::pair<std::string, int>> freq{umap.begin(), umap.end()};
  std::sort(freq.begin(), freq.end(),
            [](const auto& i, const auto& j){ return i.second > j.second; });

  // print map
  for (const auto& [key, value] : freq)
    print_map(key, '\t',  value);

  return 0;
}
