classdef DI_CMD < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        READY_TO_DRIVE(2)
        SYSTEM_ERROR(3)
        ERR_RESET(4)
    end
end