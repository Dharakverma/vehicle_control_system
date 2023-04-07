# Project Name Source Code

The folders for this project are as follows:

1. Bench Testing
> Models and supporting files for use with the LV test bench (STM32 boards, CAN busses, AMK inteverters/motors.

2. controller_ert_rtw
> a simulink-generated file dump to support embedded code generation. Can generally be ignored.

3. Plant
> Contains plant models and supporting files for simulating vehicle response at the SW level, for use in system-level testing such as in folders 1. and 6.

4. resources
> a simulink-generated file dump to support project settings and links. Can generally be ignored.

5. System_testing
> contains the system-level testing environment, where the entire control system can be simulated in the loop with a plant model that simulates vehicle response.

6. Unit_testing
> contains unit test environments for each system module.

The remaining files in this project include:
- Library models ("_lib.slx" files) of the system's modules
- enum defnitions (.m files)
