#ifndef OPERATOR_H
#define OPERATOR_H

enum operator {
    OP_ADD, 
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_END,

    OP_INVALID
};

// returns OP_INVALID on error
enum operator  operator_lookup  (char *);
int            operator_exec    (enum operator, int, int);

#endif