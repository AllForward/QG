#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
    ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack {
    ElemType *elem;
    int top;
    int size;
} SqStack;

typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;


Status initStack(SqStack *s, int sizes);

Status isEmptyStack(SqStack *s);

Status getTopStack(SqStack *s, ElemType *e);

Status clearStack(SqStack *s);

Status destroyStack(SqStack *s);

Status stackLength(SqStack *s, int *length);

Status pushStack(SqStack *s, ElemType data);

Status popStack(SqStack *s, ElemType *data);

Status StackPrint(SqStack *s); 


Status initLStack(LinkStack *s);

Status isEmptyLStack(LinkStack *s);

Status getTopLStack(LinkStack *s, ElemType *e);

Status clearLStack(LinkStack *s);

Status destroyLStack(LinkStack *s);

Status LStackLength(LinkStack *s, int *length);

Status pushLStack(LinkStack *s, ElemType data);

Status popLStack(LinkStack *s, ElemType *data);

Status LStackPrint(LinkStack *s); 


#endif // STACK_H_INCLUDED
