#ifndef clox_chunk_h
#define clox_chunk_h

#include "value.h"
#include <stdint.h>

// a one-byte operation code
typedef enum {
    OP_RETURN,
    OP_CONSTANT,
} OpCode;

// sequences of bytecode
typedef struct {
    // how many allocated entries are actually in use
    int count;
    // number of allocated elements in the array
    int capacity;
    // a series of instructions
    uint8_t* code;
    // line number
    int* lines;
    // constants pool
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif
