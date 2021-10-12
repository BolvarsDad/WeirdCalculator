#include <string.h>

#include "operator.h"
#include "xoperator.h"

static char const *operator_str[OP_END] = {
    "plus",
    "minus",
    "times",
    "divided"
};

static opfn callbacks[OP_END] = {
    fn_add,
    fn_sub,
    fn_mul,
    fn_div
};

static int
fn_add(int a, int b)
{
    return a + b;
}

static int
fn_sub(int a, int b)
{
    return a - b;
}

static int
fn_mul(int a, int b)
{
    return a * b;
}

static int
fn_div(int a, int b)
{
    return a / b;
}

enum operator
operator_lookup(char *op_tok)
{
    for(enum operator selop = 0; selop < OP_END; ++selop)
        if(strcmp(op_tok, operator_str[selop]) == 0)
            return selop;

    return OP_INVALID;
}

int
operator_exec(enum operator op, int a, int b)
{
    return callbacks[op](a, b);
}