echo off
:top
cls
Title Searcher beta 2.07
echo --=welcome to search preference beta 2.07==-
echo.
echo.
echo.

set /p search=what do you wish to find: 
echo.
echo.
echo.


find /i "%search%" ".\_searchlog.search" > "findlog.txt"
start finderFormatHTML.exe findlog.txt findlog.html

echo your search is finished
echo.
echo.
echo.

pause
echo starting findlog.html
echo restarting search
start ".\findlog.html"
echo.
echo.
echo.
goto top
exit