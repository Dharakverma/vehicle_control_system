% MUST RUN BEFORE SIMULATING VD1 DATA

load('VD1.mat')

ptCAN_AMK_ActualValues1_Left = Simulink.Bus.createObject(VD1.get('ptCAN_AMK_ActualValues1_Left'));
ptCAN_AMK_ActualValues1_Left_bus = evalin('base',ptCAN_AMK_ActualValues1_Left.busName);

ptCAN_AMK_ActualValues1_Right = Simulink.Bus.createObject(VD1.get('ptCAN_AMK_ActualValues1_Right'));
ptCAN_AMK_ActualValues1_Right_bus = evalin('base',ptCAN_AMK_ActualValues1_Right.busName);
