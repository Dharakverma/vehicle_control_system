classdef DI_CMD < Simulink.IntEnumType
    enumeration 
        DI_CMD_INIT(0)
        READY_TO_DRIVE(1)
        SYSTEM_ERROR(2)
        DI_ERR_RESET(3)
    end
end