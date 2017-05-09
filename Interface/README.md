# Interface Header

>This is a interactive interface system which can used in c++ header

## How to use:

	#include"Interface.h"

	Interface interface;

Function API:

Function | Description  | Sample
--- | --- | ---
Start() | Start Running Interface System When Setting done | interface.Start();
ShowFunctionList() | Show all the function list in the interface system | interface.ShowFunctionList();
SetListName(string name,int i)|Set Function name and index|interface.SetListname("Func1",1);
SetListHelp(string name,int i)|Set Function help or description|interface.SetListHelp("Func1 is used to exec func1",1);
|SetFunc(External_func f,int i)|Set the function|interface.SetFunc(func1,1);
|SetProgramNmae(string name)|Set The Program name|interface.SetProgramName("MyProgram");

