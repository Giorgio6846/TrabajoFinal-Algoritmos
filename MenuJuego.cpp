#include "MenuJuego.h"
//#include <Windows.h>

using namespace TrabajoFinal;

int main()
{
    srand(time(NULL));
    //ShowWindow(::GetConsoleWindow(), SW_HIDE);
    Application::Run(gcnew(TrabajoFinal::MenuJuego));

}