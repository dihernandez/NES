#include "Registers.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>
#include <bitset>

Registers::Registers() {
  program_counter = 0x0600;
  status_register = std::move(std::make_shared<StatusRegister>());
  accumulator = 0x00;
  register_x = 0x00;
  register_y = 0x00;
  stack_pointer = 0xff;
  for (int i = 0; i < 2048; i++) {
    memory[i] = 0x00;
  }
}

void Registers::read_program_conter() {
  std::cout << "program counter is: " << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(program_counter) << std::endl;
}

void Registers::read_status() {
  uint8_t status = status_register->get_status();
  std::bitset<8> s(status);
  std::cout << "status is: " << s << std::endl;
}

void Registers::read_accumulator() {
  std::cout << "accumulator is: " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(accumulator) << std::endl;
}

void Registers::read_register_x() {
  std::cout << "X register is: " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(register_x) << std::endl;
}

void Registers::read_register_y() {
  std::cout << "Y register is: " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(register_y) << std::endl;
}

void Registers::read_stack_pointer() {
  std::cout << "Stack pointer is: " << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(stack_pointer) << std::endl;
}

void Registers::read_memory_at(int memory_index) {
  if(memory_index < 0 || memory_index > 2047) {
    std::cout << "memory index out of range" << std::endl;
  } else {
    std::cout << "memory at location " << std::hex << memory_index << " is: "<< std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(memory[memory_index]) << std::endl;
  }
}

void Registers::read_all() {
  read_program_conter();
  read_status();
  read_accumulator();
  read_register_x();
  read_register_y();
  read_stack_pointer();
}

uint16_t Registers::get_program_counter() {
  return program_counter;
}

std::shared_ptr<StatusRegister> Registers::get_status_register() {
  return status_register;
}

uint8_t Registers::get_status() {
  return status_register->get_status();
}

int8_t Registers::get_accumulator() {
  return accumulator;
}

int8_t Registers::get_register_x() {
  return register_x;
}

int8_t Registers::get_register_y() {
  return register_y;
}

uint8_t Registers::get_stack_pointer() {
  return stack_pointer;
}

int8_t Registers::get_memory_at(int memory_index) {
  assert((memory_index < 0 || memory_index > 2047) && "Memory index out of range");
  return memory[memory_index];
}
