project('TestVTable', 'c')

src = ['src/data/pregen/list_intptr_t.c', 'src/BaseObject/BaseObject_events_impl.c', 'src/BaseObject/BaseObject_impl.c', 'src/ImplementedObject/ImplObject_impl.c', 'src/main.c']
testvtable = executable('testvtable', src)
test('Test VTable', testvtable, args: ['test_vtable'], suite: 'core')