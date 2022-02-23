#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "include/BaseObject/BaseObject.h"
#include "include/ImplementedObject/ImplObject.h"

int TestVTable()
{
    ImplObject ptr = ImplObject_new();

    if (ptr == NULL)
    {
        return 1;
    }
    
    if (BaseObject_A_dispatch_get((BaseObject)ptr) != 1)
    {
        return 2;
    }
    
    if (BaseObject_B_dispatch_get((BaseObject)ptr) != 2)
    {
        return 3;
    }
    if (BaseObject_C_dispatch_get((BaseObject)ptr) != 3)
    {
        return 4;
    }
    BaseObject_A_dispatch_set((BaseObject)ptr, 11);
    if (BaseObject_A_dispatch_get((BaseObject)ptr) != 11)
    {
        return 5;
    }
    
    ImplObject_destroy(ptr);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc > 0)
    {
        for (int i = 0; i < argc; ++i)
        {
            if (strcmp(argv[i], "test_vtable") == 0)
            {
                return TestVTable();
            }
        }
    }
    else
    {
        printf("Please specify which test to run.\n");
    }
    
    return 0;
}