#include <stdio.h>
#include <stdbool.h>
#include "libcstring/src/c_string.h"
#include "linenoise/linenoise.h"

char* prompt(bool isMultiLine) {
    if (isMultiLine) {
        return linenoise("");
    }

    return linenoise("@ ");
}

int main(void) {
    String* exitToken;
    String* multiLineToken;
    String* newLineToken;

    exitToken = cstring_create(exitToken, "exit");
    multiLineToken = cstring_create(multiLineToken, "```");
    newLineToken = cstring_charToString(newLineToken, '\n');

    String* input;
    char* line;

    bool isMultiLine = false;
    String* invoke;
    invoke = cstring_create(invoke, "");

    while ((line = prompt(isMultiLine)) != NULL) {
        input = cstring_create(input, line);
        if (!isMultiLine && cstring_equals(input, exitToken)) {
            break;
        } 

        if (cstring_equals(input, multiLineToken)) {
            isMultiLine = !isMultiLine;
            if (isMultiLine) {
                continue;
            }
        }

        if (!cstring_equals(input, multiLineToken)) {
            invoke = cstring_concat(invoke, 3, invoke, input, newLineToken);
        }

        if (isMultiLine) {
            continue;
        }
        
        if (input->length > 0) {
            linenoiseHistoryAdd(invoke->text);
            linenoiseHistorySave("history");
        }

        printf("You typed: %s\n", invoke->text);

        cstring_free(input);

        linenoiseFree(line); 

        cstring_free(invoke);
        invoke = cstring_create(invoke, "");
    }

    return 0;
}