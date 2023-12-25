#include "Registers.hpp"
#include <iostream>


int main() {

  Registers registers;
  registers.read_all();
  std::shared_ptr<StatusRegister> status = registers.get_status_register();
  status->set_negative(true);
  registers.read_status();
  return 0;
}
