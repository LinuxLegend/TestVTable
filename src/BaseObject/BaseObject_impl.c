#include "include/BaseObject/BaseObject.h"
#include "include/BaseObject/BaseObject_events.h"
#include "include/BaseObject/BaseObject_vtable.h"

struct BaseObject {
	event_int TestEvent;

	int A;
	int B;
	int C;

};
void BaseObject_event_TestEvent_invoke(BaseObject this, int arg)
{
	event_invoke_event_int(((struct BaseObject*)this)->TestEvent, arg);
}
void BaseObject_event_TestEvent_add(BaseObject this, callback_int handler)
{
	event_add_event_int(((struct BaseObject*)this)->TestEvent, handler);
}
void BaseObject_event_TestEvent_remove(BaseObject this, callback_int handler)
{
	event_remove_event_int(((struct BaseObject*)this)->TestEvent, handler);
}

int BaseObject_A_dispatch_get(BaseObject this)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->A_get(this);
}
int BaseObject_A_get(BaseObject this)
{
	return ((struct BaseObject*) this )->A;
}
void BaseObject_A_dispatch_set(BaseObject this, int value)
{
	((struct BaseObjectVTable*) (((void**)this)[-1]))->A_set(this, value);
}
void BaseObject_A_set(BaseObject this, int value)
{
	((struct BaseObject*) this )->A = value;
}
int BaseObject_B_dispatch_get(BaseObject this)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->B_get(this);
}
int BaseObject_B_get(BaseObject this)
{
	return ((struct BaseObject*) this )->B;
}
int BaseObject_C_dispatch_get(BaseObject this)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->C_get(this);
}
int BaseObject_C_get(BaseObject this)
{
	return ((struct BaseObject*) this )->C;
}

int BaseObject_Sum_dispatch(BaseObject this, int a, int b)
{
	return ((struct BaseObjectVTable*) (((void**)this)[-1]))->Sum(this, a, b);
}
void BaseObject_Test_dispatch(BaseObject this)
{
	((struct BaseObjectVTable*) (((void**)this)[-1]))->Test(this);
}

