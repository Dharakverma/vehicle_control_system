classdef DI_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        IDLE(2)
        STARTUP(3)
        WAITING_FOR_DRVR(4)
        DRV_START_REQ(5)
        RUNNING(6)
        ERROR(7)
    end
end