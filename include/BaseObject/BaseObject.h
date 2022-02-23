#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "include/BaseObject/BaseObject_events.h"

typedef void *BaseObject;
void BaseObject_event_TestEvent_invoke(BaseObject this, int arg);
void BaseObject_event_TestEvent_add(BaseObject this, callback_int handler);
void BaseObject_event_TestEvent_remove(BaseObject this, callback_int handler);

int BaseObject_A_dispatch_get(BaseObject this);
void BaseObject_A_dispatch_set(BaseObject this, int value);
int BaseObject_B_dispatch_get(BaseObject this);
int BaseObject_C_dispatch_get(BaseObject this);

int BaseObject_Sum_dispatch(BaseObject this, int a, int b);
void BaseObject_Test_dispatch(BaseObject this);

#endif
