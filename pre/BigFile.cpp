#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstring>
#include "MemoryRiver.hpp"

// In data first int record size, second int point to deleted data (or tail), following Dat

// In index first int record size, second head, following Block

const int kMaxNum = 350;

class Dat {
public:
  int val;
  int next = -1;
};

class Block {
public:
  int capacity = 0;
  char str[kMaxNum][64];
  int pos[kMaxNum];
  int next = -1;
};
const int kBlockSize = sizeof(Block);

MemoryRiver<Dat, 2> data("data.bin");
MemoryRiver<Block, 2> indices("index.bin");

void div(const char name[64], Block& block) {

}
bool where(const char name[64], int& block_pos, int& block_num, int& dat_pos) {
  int head;
  index.get_info(head, 2);
}
void insert(const char name[64], int val) {
  int num;
  index.get_info(num, 1);
  if(num == 0) {
    Block tmp;
    tmp.capacity = 1;
    strcpy(tmp.str[0], name);
    index.write(tmp);
  }
}
void find(const char name[64]) {
  int block_pos, block_num, dat_pos;
  if(where(name, block_pos, block_num, dat_pos)) {
    if(dat_pos == -1) {
      std::cout << "null\n";
      return;
    }
    Block block;
    index.read(block, block_pos);
    Dat head;
    data.read(head, dat_pos);
  }
  else std::cout << "null\n";
  return;
}
bool del(const char name[64], int val) {}

int main() {
  int n;
  std::cin >> n;
  
  if(!std::filesystem::exists("data.bin")) {
    std::ofstream newdata("data.bin");
  }
  data.initialise("data.bin");

  if(!std::filesystem::exists("index.bin")) {
    std::ofstream newindex("index.bin");
  }
  index.initialise("index.bin");

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