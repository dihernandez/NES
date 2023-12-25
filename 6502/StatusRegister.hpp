#ifndef StatusRegister_hpp
#define StatusRegister_hpp
#include <stdint.h>

class StatusRegister {
bool Carry;
bool Zero;
bool InterruptDisable;
bool Decimal;
bool B_flag;
bool One;
bool V_Overflow;
bool Negative;
uint8_t status;
public:
  StatusRegister();

  void set_status();

  void set_carry(bool carry);
  void set_zero(bool zero);
  void set_interrupt_disable(bool int_disable);
  void set_decimal(bool decimal);
  void set_bflag(bool b_flag);
  void set_v_overflow(bool v_overflow);
  void set_negative(bool negative);

  bool get_carry();
  bool get_zero();
  bool get_interrupt_disable();
  bool get_decimal();
  bool get_bflag();
  bool get_v_overflow();
  bool get_negative();
  uint8_t get_status();
};

#endif /* StatusRegister_hpp */
