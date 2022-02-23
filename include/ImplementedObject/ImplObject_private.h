#ifndef BASEOBJECT_PRIVATE_H
#define BASEOBJECT_PRIVATE_H
#include "include/ImplementedObject/ImplObject.h"

int ImplObject_A_get(ImplObject this);
void ImplObject_A_set(ImplObject this, int value);
int ImplObject_B_get(ImplObject this);
int ImplObject_C_get(ImplObject this);
int ImplObject_Sum(ImplObject this, int a, int b);
void ImplObject_Test(ImplObject this);
#endif
