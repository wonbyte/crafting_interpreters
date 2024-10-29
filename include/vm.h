#ifndef clox_vm_h
#define clox_vm_h

#include "Chunk.h"

#define DEBUG_TRACE_EXECUTION

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

typedef struct {
    // chunk that it executes
    Chunk* chunk;
    // instruction pointer
    uint8_t* ip;
} VM;

void initVM(void);
void freeVM(void);
InterpretResult interpret(Chunk* chunk);

#endif
