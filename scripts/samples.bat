@echo off
gcc ../main.c -o main
main.exe ../samples/matriz.txt ../samples/palavras.txt
pause >nul