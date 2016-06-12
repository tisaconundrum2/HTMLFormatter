echo off
:top
cls
Title Searcher beta 2.04
echo --=welcome to search preference beta 2.04==-
echo.
echo.
echo.

set /p search=what do you wish to find: 
echo.
echo.
echo.


find /i "%search%" ".\_searchlog (you may delete).search" > ".\findlog (you may delete).htm"


echo your search is finished
echo.
echo.
echo.

pause
cmd /c ".\findlog (you may delete).log"
echo now exiting
echo.
echo.
echo.
goto top
exit
