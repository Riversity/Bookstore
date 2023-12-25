#include <iostream>
#include "book.hpp"
#include "file.hpp"
int main() {
  int n;
  std::cin >> n;
  
  if(!std::filesystem::exists("data.bin")) {
    std::ofstream newdata("data.bin");
  }
  data.initialise("data.bin");

  if(!std::filesystem::exists("indices.bin")) {
    std::ofstream newindices("indices.bin");
  }
  indices.initialise("indices.bin");

  std::string str;
  char name[64];
  int val;

  for (int i = 0; i < n; ++i) {
    std::cin >> str;
    if (str == "insert") {
      std::cin >> name >> val;
      insert(name, val);
    }
    else if (str == "find") {
      std::cin >> name;
      find(name);
    }
    else if (str == "delete") {
      std::cin >> name >> val;
      del(name, val);
    }
  }

  return 0;
}