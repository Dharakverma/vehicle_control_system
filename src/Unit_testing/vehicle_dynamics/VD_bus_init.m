% 1. RUN THE TEST CASE .MAT FILE (eg. VD1.mat)
% 2. RUN THIS SCRIPT
% 3. RUN THE ROOT INPORT MAPPER, SUPPLYING THE SAME .MAT AS ABOVE
% 4. RUN THE .SLX SIMULATION

ptCAN_AMK_ActualValues1_Left = Simulink.Bus.createObject(VD_inputData.get('ptCAN_AMK_ActualValues1_Left'));
ptCAN_AMK_ActualValues1_Left_bus = evalin('base',ptCAN_AMK_ActualValues1_Left.busName);

ptCAN_AMK_ActualValues1_Right = Simulink.Bus.createObject(VD_inputData.get('ptCAN_AMK_ActualValues1_Right'));
ptCAN_AMK_ActualValues1_Right_bus = evalin('base',ptCAN_AMK_ActualValues1_Right.busName);
