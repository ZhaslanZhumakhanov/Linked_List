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
    Append(list, 42);
    AssertEq(1, Length(list), "Length([42]) should be 1");
    AssertEq(42, GetAt(list, 0), "GetAt([42], 0) should be 42");
    Prepend(list,40);
    printf("%d ", Length(list));
    for (int i=0; i<Length(list); i++){
        printf("%d ",GetAt(list,i));
    }
    printf(" ");
    AssertEq(2,Length(list),"Length");
    AssertEq(40,GetAt(list,0),"Prepend");
    List* list2 = NewList();
    AppendAll(list,list2);
    printf("%d ", Length(list));
    for (int i=0; i<Length(list); i++){
        printf("%d ",GetAt(list,i));
    }
    printf(" ");
    AssertEq(40,GetAt(list,0),"AppendAll_1");
    AssertEq(42,GetAt(list,1), "AppendAll_2");
    List* list3= NewList();
    Append(list3,1);
    AppendAll(list3,list);
    printf("%d ", Length(list3));
    for (int i=0; i<Length(list3); i++){
        printf("%d ",GetAt(list3,i));
    }
    AssertEq(40,GetAt(list3,1),"AppendAll_3");
    AssertEq(3,Length(list3),"AppendAll_4");
    DestroyList(list);
}