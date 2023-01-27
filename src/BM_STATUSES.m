classdef BM_STATUSES < Simulink.IntEnumType
    enumeration 
        BM_UNKNOWN(0)
        BM_INIT(1)
        BM_IDLE(2)
        BM_STARTUP(3)
        INIT_PRECHARGE(4)
        PRECHARGE(5)
        BM_RUNNING(6)
        ERR_PRECHARGE_CLOSED(7)
        ERR_STARTUP(8)
        ERR_INIT_PRECHARGE(9)
        ERR_PRECHARGE(10)
        ERR_RUNNING(11)
        ERR_ALL_CLOSED(12)
        ERR_HV_POSITIVE(13)
    end
end