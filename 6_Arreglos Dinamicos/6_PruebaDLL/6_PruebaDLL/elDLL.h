#pragma once
#include <iostream>
#include <cstring>

extern "C"
{
	__declspec(dllimport) const char* GetCodename();
	__declspec(dllexport) double sumar(double a, double b);

    __declspec(dllexport) const char* concatenar(const char* A, const char* B) {
        size_t lenA = strlen(A);
        size_t lenB = strlen(B);
        char* resultado = new char[lenA + lenB + 1];
        strcpy_s(resultado, lenA + lenB + 1, A);
        strcat_s(resultado, lenA + lenB + 1, B);
        return resultado;
    }
}