classdef MI_CMD < Simulink.IntEnumType
    enumeration 
        CMD_INIT(0)
        IDLE(1)
        CMD_STARTUP(2)
        CMD_SHUTDOWN(3)
        ERR_RESET(4)
    end
end