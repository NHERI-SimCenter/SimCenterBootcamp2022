#include <iostream>
#include <string>


int main(int argv, char **argc) {
  std::string pName = argc[0];
  std::string str;
  std::cout << "Enter Name: ";
  std::cin >> str;

  if (pName == "./a.out")
    str += " the lazy sod";

  str += " says ";
  str = str + "HELLO World";
  std::cout << str << "\n";

  return 0;
}
