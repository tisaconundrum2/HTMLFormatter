@echo off
::Update Finder
::this will be used to update the finder file

::prompt
:find the data
::import it into a file
::exit the program


title Finder beta 2.04
echo -=-Welcome to Finder 1.04-=-
echo Now updating index file.
REM clear and refresh the searchlog
echo. > ".\_searchlog.search"

dir /b/o/w/s C:\ >> .\_searchlog.search
dir /b/o/w/s E:\ >> .\_searchlog.search

del /f/s/q ".\_searchlog.search"
ren ".\_searchlog.search" "_searchlog(you may delete).search"
echo indexing is finished
echo exiting in 3 seconds
timeout /t 3 > nul
