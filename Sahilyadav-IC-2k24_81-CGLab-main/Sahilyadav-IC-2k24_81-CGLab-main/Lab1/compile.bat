@echo off
echo =========================================================
echo Compiling CGM Lab Assignment 1 - Basic Shapes
echo Student: Srishtee Dayma (Roll: 104, IC-2k24)
echo =========================================================

g++ assignment1_basic_shapes.cpp -o assignment1_basic_shapes.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

if %ERRORLEVEL% equ 0 (
    echo [SUCCESS] Compilation finished successfully!
    echo Running program...
    assignment1_basic_shapes.exe
) else (
    echo [ERROR] Compilation failed! Check compiler output.
)
pause
