@echo off
gcc -Wall -Wextra -std=c99 %1 -o %~dpn1.exe
if %errorlevel% equ 0 (
    echo 编译成功，正在运行...
    %~dpn1.exe
    echo.
    echo 程序执行完成
    pause
) else (
    echo 编译失败
    pause
)