from pylab import *
#ce script gere les calculs de matrice
#enfin il essaye

def Matrice()
	

//à inclure dans le fichier cpp	
#include <Python.h>

int
main(int argc, char *argv[])
{
  Py_SetProgramName(argv[0]);  /* optional but recommended */
  Py_Initialize();
  PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n");
  Py_Finalize();
  return 0;
}	
