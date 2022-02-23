#include "include/ImplementedObject/ImplObject.h"
#include "include/ImplementedObject/ImplObject_private.h"
#include "include/BaseObject/BaseObject_events.h"
#include "include/BaseObject/BaseObject_vtable.h"
#include <stdio.h>
#include <stdlib.h>

struct ImplObject {
	event_int TestEvent;
	int A;
	int B;
	int C;
};

static struct BaseObjectVTable ImplObjectVTable = (struct BaseObjectVTable){
	.A_get = ImplObject_A_get,
	.A_set = ImplObject_A_set,
	.B_get = ImplObject_B_get,
	.C_get = ImplObject_C_get,
	.Sum = ImplObject_Sum,
	.Test = ImplObject_Test
};

void ImplObject_event_TestEvent_invoke(ImplObject this, int arg)
{
	event_invoke_event_int(((struct ImplObject*)this)->TestEvent, arg);
}
void ImplObject_event_TestEvent_add(ImplObject this, callback_int handler)
{
	event_add_event_int(((struct ImplObject*)this)->TestEvent, handler);
}
void ImplObject_event_TestEvent_remove(ImplObject this, callback_int handler)
{
	event_remove_event_int(((struct ImplObject*)this)->TestEvent, handler);
}

int ImplObject_A_dispatch_get(ImplObject this)
{
	return ((struct BaseObjectVTable*) (this - 1) )->A_get(this);
}
int ImplObject_A_get(ImplObject this)
{
	return ((struct ImplObject*) this )->A;
}
void ImplObject_A_dispatch_set(ImplObject this, int value)
{
	((struct BaseObjectVTable*) (this-1) )->A_set(this, value);
}
void ImplObject_A_set(ImplObject this, int value)
{
	((struct ImplObject*) this )->A = value;
}
int ImplObject_B_dispatch_get(ImplObject this)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->B_get(this);
}
int ImplObject_B_get(ImplObject this)
{
	return ((struct ImplObject*) this )->B;
}
int ImplObject_C_dispatch_get(ImplObject this)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->C_get(this);
}
int ImplObject_C_get(ImplObject this)
{
	return ((struct ImplObject*) this )->C;
}

int ImplObject_Sum_dispatch(ImplObject this, int a, int b)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->Sum(this, a, b);
}
void ImplObject_Test_dispatch(ImplObject this)
{
	((struct BaseObjectVTable*) (((void**)this)[-1]))->Test(this);
}

int ImplObject_Sum(ImplObject this, int a, int b)
{
	return a + b;
}

void ImplObject_Test(ImplObject this)
{
	printf("Just a test!\n");
}

ImplObject ImplObject_new()
{
	void** newObj = (void**)malloc(sizeof(struct ImplObject) + sizeof(void*));
	if (newObj == NULL)
		return NULL;
	*newObj = &ImplObjectVTable;
	struct ImplObject* ptr = (struct ImplObject*)(&newObj[1]);
	ptr->A = 1;
	ptr->B = 2;
	ptr->C = 3;
	ptr->TestEvent = event_new_event_int();
	return (ImplObject)ptr;
}
void ImplObject_destroy(ImplObject obj)
{
	free(&((void**)obj)[-1]);
}