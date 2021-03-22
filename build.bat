@ECHO off
CLS
ECHO.
ECHO Building for Windows ...
TCC      CALU.C -bench -v
IF %ERRORLEVEL% GEQ 1 SET ERRORCHECK=1
ECHO.
ECHO Building for Linux   ...
WSL  gcc CALU.C -o CALU.ELF
WSL  strip -sx --strip-unneeded -R .gnu.version --strip-all --remove-section=.comment --remove-section=.note CALU.ELF
IF %ERRORLEVEL% GEQ 1 SET ERRORCHECK=1
IF "%ERRORCHECK%"=="1" PAUSE
SET ERRORCHECK==0
