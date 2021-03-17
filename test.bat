@ECHO OFF
ECHO Running Windows build ...
CALU
PAUSE
ECHO Showing help...
CALU ?
PAUSE
ECHO Running Linux   build ...
WSL  ./CALU.ELF
PAUSE
ECHO Showing help...
WSL  ./CALU.ELF ?
PAUSE

