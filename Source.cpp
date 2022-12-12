#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <Python.h>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"Python");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

int main()
{
	
	/*CallProcedure("printsomething");
	 *cout << callIntFunc("PrintMe", "House") << endl;
	 *cout << callIntFunc("SquareValue", 2);
	 */

	// declare variables for user input integerfor main menu selection
	// and user input string for selection of item to be counted for frequency of purchase
	int userInt;
	string userStr;
	ifstream InventoryFile;

	// output program title and main menu options to console
	cout << "Grocery Tracking Program" << endl << endl;
	cout << "1. Produce a list of all items purchased in a given day with quantities" << endl;
	cout << "2. Produce the number of times a specific item was purchased on a given day" << endl;
	cout << "3. Produce a text-based histogram listing all the items purchased and frequency of purchases in a given day"
		 << endl;
	cout << "4. Exit" << endl;
	cout << "Select option: ";
	
	// set userInt variable with user input
	cin >> userInt;

	//test userInt for invalid input
	while (userInt < 1 && userInt > 4) {
		cout << "Error- user input must be integer 1, 2, 3, or 4" << endl;
		cin >> userInt;
	}

	// while userInt variable does not represent the integer 4 process run loop
	while (userInt != 4) {

		if (userInt == 1) {
			//call Python function to output all items purchased and frequency of purchases.
			CallProcedure("ListAll");

		}
		else if (userInt == 2) {
			//activate Python function to request search and count for frequency of specified item purchase
			CallProcedure("ItemFrequency");
		}
		else if (userInt == 3) {
			//activate Python function to produce text-based histogram for frequency of all items purchased on given day
			CallProcedure("HistogramList");
		}
		else {
			cout << "Invalid input- /nuser input options are limited to integers 1, 2, 3 and 4." << endl << endl;
		}
		
		userInt = 0;
		// output program title and main menu options to console
		cout << "Grocery Tracking Program" << endl << endl;
		cout << "1. Produce a list of all items purchased in a given day with quantities" << endl;
		cout << "2. Produce the number of times a specific item was purchased on a given day" << endl;
		cout << "3. Produce a text-based histogram listing all the items purchased and frequency of purchases in a given day"
			<< endl;
		cout << "4. Exit" << endl;
		cout << "Select option: ";

		// set userInt variable with user input
		cin >> userInt;

		//test userInt for invalid input
		while (userInt < 1 && userInt > 4) {
			cout << "Error- user input must be integer 1, 2, 3, or 4" << endl;
			cin >> userInt;
		}
	}

	return 0;
}