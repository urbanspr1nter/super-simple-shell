#include <stdio.h>
#include "libcstring/src/c_string.h"
#include "linenoise/linenoise.h"

int main(void) {
    String* upArrowSeq;
    String* downArrowSeq;

    upArrowSeq = cstring_create(upArrowSeq, "\x1b[A");
    downArrowSeq = cstring_create(downArrowSeq, "\x1b[B");

    String* input;
    String* token;
    char* line;
    
    while ((line = linenoise("@ ")) != NULL) {
        input = cstring_create(input, line);

        token = cstring_create(token, "exit");
        if (cstring_equals(input, token)) {
            break;
        }
        
        if (input->length > 0) {
            linenoiseHistoryAdd(input->text);
            linenoiseHistorySave("history");
        }

        printf("You typed: %s\n", input->text);

        cstring_free(token);
        cstring_free(input);
        linenoiseFree(line); 
    }

    return 0;
}