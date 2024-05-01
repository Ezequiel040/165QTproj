
#ifndef TASK_H
#define TASK_H

#include <QString>

class Task {
public:
    virtual ~Task() {}
    virtual QString getText() const = 0; // Pure virtual function

};

#endif // TASK_H
