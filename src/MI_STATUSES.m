classdef MI_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        STS_INIT(1)
        STARTUP(2)
        RUNNING(3)
        SHUTDOWN(4)
        MI_STS_ERROR(5)
        OFF(6)
    end
end