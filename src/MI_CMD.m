classdef MI_CMD < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        IDLE(2)
        STARTUP(3)
        SHUTDOWN(4)
        ERR_RESET(5)
    end
end