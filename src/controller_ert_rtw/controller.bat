
set MATLAB=C:\Program Files\MATLAB\R2022b

cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  -f controller.mk all) else ("C:\PROGRA~1\MATLAB\R2022b\bin\win64\gmake"  -f controller.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1