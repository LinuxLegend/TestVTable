#ifndef BASEOBJECT_VTABLE_H
#define BASEOBJECT_VTABLE_H
#include "include/BaseObject/BaseObject.h"

struct BaseObjectVTable {
	int (*A_get)(BaseObject this);
	void (*A_set)(BaseObject this, int value);
	int (*B_get)(BaseObject this);
	int (*C_get)(BaseObject this);

	int (*Sum)(BaseObject this, int a, int b);
	void (*Test)(BaseObject this);

};
#endif
