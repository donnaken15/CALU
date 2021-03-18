@ECHO OFF
ECHO Running Windows build ...
start "" CALU
:#PAUSE
ECHO Showing help...
CALU ?
PAUSE
ECHO Running Linux   build ...
start "" WSL  ./CALU.ELF
:#PAUSE
ECHO Showing help...
WSL  ./CALU.ELF ?
PAUSE

