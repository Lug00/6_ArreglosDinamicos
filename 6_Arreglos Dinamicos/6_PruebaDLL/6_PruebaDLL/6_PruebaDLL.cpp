// 6_PruebaDLL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>

int main()
{
    puts("Cargando DLL");

    //Cargar la DLL
    HINSTANCE elDLL = LoadLibrary(L"6_dll.dll");

    //Comprobar si cargó la dll
 
    if (elDLL != NULL)
    {
        puts("Se cargo la DLL :)");
        typedef const char* (*GetCodenameFunc)();
        GetCodenameFunc getCodename = reinterpret_cast<GetCodenameFunc>(GetProcAddress(elDLL, "GetCodename"));
        if (getCodename != NULL)
        {
            const char* mensaje = getCodename();
            std::cout << "desde la DLL" << mensaje << "\n";
        }
        else
        {
            puts("no se encontro la funcion :(");
        }

        //Cargar la funcion SUMAR
        typedef double (*sumarFunc)(double a, double b);
        sumarFunc sumar = reinterpret_cast<sumarFunc>(GetProcAddress(elDLL, "sumar"));
        if (sumar != NULL)
        {
            std::cout << "prueba de suma: " << sumar(3.1416, 1.414);
        }
        FreeLibrary(elDLL);
    }
    else
    {
        puts("No se pudo cargar la DLL :(");
    }
    
    HINSTANCE hDLL = LoadLibrary(L"6_dll.dll"); // Cargamos la DLL

    if (hDLL == nullptr) {
        std::cerr << "No se pudo cargar la DLL." << "\n";
        return 1;
    }

    typedef const char* (*ConcatenarFunc)(const char*, const char*);
    ConcatenarFunc concatenar = reinterpret_cast<ConcatenarFunc>(GetProcAddress(hDLL, "concatenar"));

    if (concatenar == nullptr) {
        std::cerr << "No se pudo encontrar la funcion en la DLL." << "\n";
        return 1;
    }

    const char* uno = "Hola";
    const char* dos = "Mundo";
    const char* resultado = concatenar(uno, dos);

    std::cout << resultado << std::endl;

    delete[] resultado;

    FreeLibrary(hDLL); // Liberamos la DLL

    return 0;
}
