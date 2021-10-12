#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"
#include "operator.h"
#include "number.h"

static void
usage(char *pre_msg)
{
    static char const *lines[] = {
        "wcalc - weird calculator with purposefully bad UI",
        "usage: wcalc <expr>",
        "expr: A,op,B",
        "A and B: numbers 0..10 written in American English, lowercase.",
        "op: an operator, one of {plus, minus, times, divided}",
        "",
        "example:",
        "$ wcalc three,plus,ten",
        "thirteen",
        NULL
    };

    if(pre_msg)
        puts(pre_msg);

    putsv(lines);
    exit(1);
}

int
main(int argc, char **argv)
{
    char *tokens[3];
    int op;
    int arg_a;
    int arg_b;

    if(argc < 2)
        usage("E: missing argument");

    tokens[0] = strtok(argv[1], ",");
    tokens[1] = strtok(NULL, ",");
    tokens[2] = strtok(NULL, ",");

    for(int i = 0; i < 3; ++i)
        if(tokens[i] == NULL)
            usage("E: expr has too few members");

    op = operator_lookup(tokens[1]);
    arg_a = number_from_str(tokens[0]);
    arg_b = number_from_str(tokens[2]);

    if(arg_a == -1 || arg_b == -1 || op == OP_INVALID)
        usage("E: unrecognized number or operator");

    puts(number_to_str(operator_exec(op, arg_a, arg_b)));

    return 0;
}