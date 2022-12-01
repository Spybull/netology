#ifndef COUNTER_H
#define COUNTER_H

class Counter {

    int count;

    public:
        Counter();
        Counter(int);

        int get();
        int inc();
        int dec();
};

#endif