@echo off
echo =========================================================
echo Compiling CGM Lab Assignment 2 - DDA Line Algorithm
echo Student: Srishtee Dayma (Roll: 104, Batch: IC-2k24)
echo =========================================================

g++ assignment2_dda_line.cpp -o assignment2_dda_line.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

if %ERRORLEVEL% equ 0 (
    echo [SUCCESS] Compilation finished successfully!
    echo Running program...
    assignment2_dda_line.exe
) else (
    echo [ERROR] Compilation failed! Check compiler output.
)
pause
