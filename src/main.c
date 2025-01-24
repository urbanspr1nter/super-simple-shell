#include <stdio.h>
#include "libcstring/src/c_string.h"


int main(void) {
    String* s;
    s = cstring_create(s, "Hello, world!");

    printf("%s\n", s->text);

    return 0;
}