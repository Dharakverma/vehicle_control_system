classdef BM_STATUSES < Simulink.IntEnumType
    enumeration 
        UNKNOWN(0)
        INIT(1)
        IDLE(2)
        STARTUP(3)
        INIT_PRECHARGE(4)
        PRECHARGE(5)
        RUNNING(6)
        ERR_PRECHARGE_CLOSED(7)
        ERR_STARTUP(8)
        ERR_INIT_PRECHARGE(9)
        ERR_PRECHARGE(10)
        ERR_RUNNING(11)
        ERR_ALL_CLOSED(12)
        ERR_HV_POSITIVE(13)
    end
end