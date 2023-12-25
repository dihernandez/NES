#include "StatusRegister.hpp"
#include <cassert>
#include <iostream>
#include <bitset>

StatusRegister::StatusRegister() {
  Carry = false;
  Zero = false;
  InterruptDisable = false;
  Decimal = false;
  B_flag = false;
  One = true;
  V_Overflow = false;
  Negative = false;
  set_status();
  // std::bitset<8> s(status);
  // std::cout << "after init, status is " << s << std::endl;
  assert(status == 0b00100000);
}

void StatusRegister::set_status() {
  uint8_t new_status = 0b00000000;
  if(Carry) {
    new_status |= 0b00000001;
  }
  if(Zero) {
    new_status |= 0b00000010;
  }
  if(InterruptDisable) {
    new_status |= 0b00000100;
  }
  if(Decimal) {
    new_status |= 0b00001000;
  }
  if(B_flag) {
    new_status |= 0b00010000;
  }
  if(One) {
    new_status |= 0b00100000;
  }
  if(V_Overflow) {
    new_status |= 0b01000000;
  }
  if(Negative) {
    new_status |= 0b10000000;
  }
  status = new_status;
}

void StatusRegister::reset_status() {
  set_carry(false);
  set_zero(false);
  set_interrupt_disable(false);
  set_decimal(false);
  set_bflag(false);
  set_v_overflow(false);
  set_negative(false);
}

void StatusRegister::set_carry(bool carry) {
  Carry = carry;
  set_status();
}

void StatusRegister::set_zero(bool zero) {
  Zero = zero;
  set_status();
}

void StatusRegister::set_interrupt_disable(bool int_disable) {
  InterruptDisable = int_disable;
  set_status();
}

void StatusRegister::set_decimal(bool decimal) {
  Decimal = decimal;
  set_status();
}

void StatusRegister::set_bflag(bool b_flag) {
  B_flag = b_flag;
  set_status();
}

void StatusRegister::set_v_overflow(bool v_overflow) {
  V_Overflow = v_overflow;
  set_status();
}

void StatusRegister::set_negative(bool negative) {
  Negative = negative;
  set_status();
}

bool StatusRegister::get_carry() {
  return Carry;
}

bool StatusRegister::get_zero() {
  return Zero;
}

bool StatusRegister::get_interrupt_disable() {
  return InterruptDisable;
}

bool StatusRegister::get_decimal() {
  return Decimal;
}

bool StatusRegister::get_bflag() {
  return B_flag;
}

bool StatusRegister::get_v_overflow() {
  return V_Overflow;
}

bool StatusRegister::get_negative() {
  return Negative;
}

uint8_t StatusRegister::get_status() {
  return status;
}
