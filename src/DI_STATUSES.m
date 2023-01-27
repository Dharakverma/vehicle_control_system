classdef DI_STATUSES < Simulink.IntEnumType
    enumeration 
        DI_UNKNOWN(0)
        DI_STS_INIT(1)
        DI_IDLE(2)
        DI_STARTUP(3)
        WAITING_FOR_DRVR(4)
        DRV_START_REQ(5)
        DI_RUNNING(6)
        DI_ERROR(7)
    end
end