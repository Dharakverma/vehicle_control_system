classdef MI_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        STARTUP(2)
        RUNNING(3)
        SHUTDOWN(4)
        ERROR(5)
        ERR_STARTUP(6)
        ERR_RUNNING(7)
        ERR_SHUTDOWN(8)
    end
end