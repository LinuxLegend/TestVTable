#ifndef IMPLOBJECT_H
#define IMPLOBJECT_H
#include "include/BaseObject/BaseObject_events.h"

typedef void* ImplObject;

ImplObject ImplObject_new();
void ImplObject_destroy(ImplObject obj);
void ImplObject_event_TestEvent_invoke(ImplObject this, int arg);
void ImplObject_event_TestEvent_add(ImplObject this, callback_int handler);
void ImplObject_event_TestEvent_remove(ImplObject this, callback_int handler);

int ImplObject_A_dispatch_get(ImplObject this);
void ImplObject_A_dispatch_set(ImplObject this, int value);
int ImplObject_B_dispatch_get(ImplObject this);
int ImplObject_C_dispatch_get(ImplObject this);

int ImplObject_Sum_dispatch(ImplObject this, int a, int b);
void ImplObject_Test_dispatch(ImplObject this);
#endif