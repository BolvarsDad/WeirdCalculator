#ifndef XOPERATOR_H
#define XOPERATOR_H

typedef int (*opfn)(int, int);

static int  fn_add  (int, int);
static int  fn_sub  (int, int);
static int  fn_mul  (int, int);
static int  fn_div  (int, int);

#endif