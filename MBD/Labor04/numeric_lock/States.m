classdef States < Simulink.IntEnumType
  enumeration
    INIT(0),
    IDLE(1),
    KEY_PRESSED(2),
    READING(3),
    CHECK(4),
    UNLOCK(5),
    WRONG_CODE(6),
    SYSTEM_LOCKDOWN(7),
    LOCKED (8)
  end
end 
