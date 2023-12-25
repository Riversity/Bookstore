#ifndef _file_h
#define _file_h

#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <cstring>
#include "memory.hpp"

// In data first int record size, second int point to deleted data (or tail), following Dat

// In indices first int record size, second head, following Block

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
MemoryRiver<Block, 2> indices("indices.bin");

void div(const char name[64], Block& block) {

}
bool where(const char name[64], int& block_pos, int& block_num, int& dat_pos) {
  int head;
  indices.get_info(head, 2);
}
void insert(const char name[64], int val) {
  int num;
  indices.get_info(num, 1);
  if(num == 0) {
    Block tmp;
    tmp.capacity = 1;
    strcpy(tmp.str[0], name);
    indices.write(tmp);
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
    indices.read(block, block_pos);
    Dat head;
    data.read(head, dat_pos);
  }
  else std::cout << "null\n";
  return;
}
bool del(const char name[64], int val) {}

#endif
