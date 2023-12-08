#include"FileRiver.hpp"
#include<iostream>
int main(){
  MemoryRiver<double,3> m;
  double a =114.514,b=123.345,c,d;
  m.initialise("1.txt");
  auto k = m.write(a);
  auto l = m.write(b);
  m.update(b,k);
  m.read(c,k);
  m.read(d,l);
  std::cout<<c<<d;
}