classdef DI_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        IDLE(2)
        STARTUP(3)
        DRV_START_REQ(4)
        RUNNING(5)
        ERR_STARTUP(6)
        ERR_RUNNING(7)
    end
end