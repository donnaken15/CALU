@ECHO off
CLS
ECHO.
ECHO Building for Windows ...
TCC      CALU.C -bench -v
IF %ERRORLEVEL% GEQ 1 SET ERRORCHECK=1
ECHO.
ECHO Building for Linux   ...
WSL  gcc CALU.C -o CALU.ELF
IF %ERRORLEVEL% GEQ 1 SET ERRORCHECK=1
ECHO Compiling man page

ECHO.
IF "%ERRORCHECK%"=="1" PAUSE
