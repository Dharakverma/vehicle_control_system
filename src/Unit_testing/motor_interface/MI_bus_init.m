% MUST RUN BEFORE SIMULATING VD1 DATA

load('MI1.mat')

ptCAN_AMK_ActualValues1_Left = Simulink.Bus.createObject(MI1.get('ptCAN_AMK_ActualValues1_Left'));
ptCAN_AMK_ActualValues1_Left_bus = evalin('base',ptCAN_AMK_ActualValues1_Left.busName);
ptCAN_AMK_ActualValues2_Left = Simulink.Bus.createObject(MI1.get('ptCAN_AMK_ActualValues2_Left'));
ptCAN_AMK_ActualValues2_Left_bus = evalin('base',ptCAN_AMK_ActualValues2_Left.busName);

ptCAN_AMK_ActualValues1_Right = Simulink.Bus.createObject(MI1.get('ptCAN_AMK_ActualValues1_Right'));
ptCAN_AMK_ActualValues1_Right_bus = evalin('base',ptCAN_AMK_ActualValues1_Right.busName);
ptCAN_AMK_ActualValues2_Right = Simulink.Bus.createObject(MI1.get('ptCAN_AMK_ActualValues2_Right'));
ptCAN_AMK_ActualValues2_Right_bus = evalin('base',ptCAN_AMK_ActualValues2_Right.busName);