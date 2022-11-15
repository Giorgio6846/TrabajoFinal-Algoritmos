#include "MenuJuego.h"

using namespace TrabajoFinal;

int main()
{
    srand(time(NULL));
    Application::Run(gcnew(TrabajoFinal::MenuJuego));
}