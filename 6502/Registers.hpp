#ifndef Registers_hpp
#define Registers_hpp

#include "StatusRegister.hpp"
#include <stdint.h>
#include <memory>

class Registers {
uint16_t program_counter;
std::shared_ptr<StatusRegister> status_register;
int8_t accumulator;
int8_t register_x;
int8_t register_y;
uint8_t stack_pointer;
int8_t memory[2048];
public:
  Registers();
  void read_program_conter();
  void read_status();
  void read_accumulator();
  void read_register_x();
  void read_register_y();
  void read_stack_pointer();
  void read_memory_at(int memory_index);
  void read_all();

  uint16_t get_program_counter();
  std::shared_ptr<StatusRegister> get_status_register();
  uint8_t get_status();
  int8_t get_accumulator();
  int8_t get_register_x();
  int8_t get_register_y();
  uint8_t get_stack_pointer();
  int8_t get_memory_at(int memory_index);

  void set_program_counter(uint16_t new_pc);
  void set_status(uint8_t new_status);
  void set_accumulator(int8_t new_accumulator);
  void set_register_x(int8_t new_x);
  void set_register_y(int8_t new_y);
  void set_stack_pointer(uint8_t new_sp);
  bool set_memory_at(int8_t data, int memory_index);

};

#endif /* Registers_hpp */
