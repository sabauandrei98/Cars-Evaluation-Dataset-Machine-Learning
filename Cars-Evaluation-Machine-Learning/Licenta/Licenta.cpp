#include <iostream>
#include <Windows.h>
#include <crtdbg.h>
#include "UI.h"
#include "TestsControler.h"
using namespace std;

//TRUE -> PROGRAM
//FALSE -> TESTS
#define NORMAL_FLOW true

int main()
{
	if (NORMAL_FLOW)
		UI ui;
	else
		TestsControler tests;

	system("pause");
	_CrtDumpMemoryLeaks();
    return 0;
}

