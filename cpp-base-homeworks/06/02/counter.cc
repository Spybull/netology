#include "counter.h"

Counter::Counter() : Counter(1) {}
Counter::Counter(int _count) : count(_count) {}

int Counter::get() { return this->count; }
int Counter::inc() { return this->count++; }
int Counter::dec() { return this->count--; }