% 1. RUN THE TEST CASE .MAT FILE (eg. MI1.mat)
% 2. RUN THIS SCRIPT
% 3. RUN THE ROOT INPORT MAPPER, SUPPLYING THE SAME .MAT AS ABOVE
% 4. RUN THE .SLX SIMULATION

ptCAN_AMK_ActualValues1_Left = Simulink.Bus.createObject(MI_inputData.get('ptCAN_AMK_ActualValues1_Left'));
ptCAN_AMK_ActualValues1_Left_bus = evalin('base',ptCAN_AMK_ActualValues1_Left.busName);
ptCAN_AMK_ActualValues2_Left = Simulink.Bus.createObject(MI_inputData.get('ptCAN_AMK_ActualValues2_Left'));
ptCAN_AMK_ActualValues2_Left_bus = evalin('base',ptCAN_AMK_ActualValues2_Left.busName);

ptCAN_AMK_ActualValues1_Right = Simulink.Bus.createObject(MI_inputData.get('ptCAN_AMK_ActualValues1_Right'));
ptCAN_AMK_ActualValues1_Right_bus = evalin('base',ptCAN_AMK_ActualValues1_Right.busName);
ptCAN_AMK_ActualValues2_Right = Simulink.Bus.createObject(MI_inputData.get('ptCAN_AMK_ActualValues2_Right'));
ptCAN_AMK_ActualValues2_Right_bus = evalin('base',ptCAN_AMK_ActualValues2_Right.busName);