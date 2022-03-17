#include <iostream>
#include <string>

using namespace std;

int main() {
  char arr[11] = "0123456789";

  std::cout << "Teste" << " " << arr[5];

  for (int i=1; i<=5; i++) {
    std::cout << "Valor " << i << "\n";
  }
  return 0;
}
