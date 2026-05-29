#ifndef MEMORY_H
#define MEMORY_H

class Memory {
public:
    void add(double value) {
        stored += value;
    }
    void sub(double value) {
        stored -= value;
    }
    double recall() const {
        return stored;
    }
    void clear() {
        stored = 0;
    }
    double getValue() const {
        return stored;
    }
    void setValue(double value) {
        stored = value;
    }
private:
    double stored = 0;
};

#endif // MEMORY_H
