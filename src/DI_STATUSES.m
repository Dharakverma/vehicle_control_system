classdef DI_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        IDLE(2)
        STARTUP(3)
        DRV_START_REQ(4)
        RUNNING(5)
        ERROR(6)
        ERR_STARTUP(7)
        ERR_RUNNING(8)
    end
end