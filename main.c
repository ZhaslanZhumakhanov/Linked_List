#include "list.h"
#include <stdio.h>
#include <stdlib.h>

static void AssertEq(int expected, int actual, const char* msg) {
    if (expected != actual) {
        printf("Test failed: %s\n expected %d but got %d\n", msg, expected, actual);
        exit(-1);
    }
}

int main(void) {
    List* list = NewList();
    AssertEq(0, Length(list), "empty list length should be zero");
    Append(list, 42); // ([42]) - список
    AssertEq(1, Length(list), "Length([42]) should be 1");
    AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
    Prepend(list,1); // ([1] [42])
    AssertEq(1,GetAt(list,0),"Prepend_1");
    AssertEq(42,GetAt(list,1),"Prepend_2");
    RemoveAll(list); // ()
    Prepend(list,2); // ([2])
    AssertEq(2,GetAt(list,0),"Prepend_3 and RemoveAll_1");
    RemoveAll(list); // ()
    AssertEq(0,Length(list),"RemoveAll_2");
    Append(list,1); // ([1])
    InsertAt(list,0,2); // ([1] [2])
    AssertEq(2,GetAt(list,1),"InsertAt_1");
    AssertEq(1,GetAt(list,0),"InsertAt_2");
    //InsertAt(list,2,3);
    // AssertEq(1,GetAt(list,0),"InsertAt_3"); Выход за границы списка
    List* list2 = NewList();
    AppendAll(list2,list); // ([1] [2])
    AssertEq(2,GetAt(list,1),"AppendAll_1");
    AppendAll(list,list2); // ([1] [2] [1] [2])
    AssertEq(2,GetAt(list,3),"AppendAll_2");
    List* list3 = NewList();
    AppendAll(list,list3); // ([1] [2] [1] [2])
    //AssertEq(2,GetAt(list,4),"AppendAll_3"); Выход за границы списка
    DestroyList(list3);
    DestroyList(list2);
    //AssertEq(0,Length(list2),"Destroy"); Нахождение длины несуществующего списка
    RemoveAt(list,3); // ([1] [2] [1])
    AssertEq(3,Length(list),"RemoveAt_1");
    RemoveAt(list,0); // ([2] [1])
    AssertEq(2,GetAt(list,0),"RemoveAt_2");
    //RemoveAt(list,2); //Выход за границы списка
    int x=Pop(list); // ([2])
    AssertEq(1,x,"Pop_1");
    x=Dequeue(list);
    AssertEq(2,x,"Pop_1");
    DestroyList(list);
    //AssertEq(0,Length(list),"Deque and Destroy"); Нахождение длины несуществующего списка
}