// todotask.h
#ifndef TODOTASK_H
#define TODOTASK_H

#include "task.h"
#include <QString>

class TodoTask : public Task {
public:
    TodoTask(const QString &text, const QString &dueDate, const QString &priority, const QString &label, const QString &loc)
        : m_text(text), m_dueDate(dueDate), m_priority(priority), m_label(label), m_loc(loc) {}

    QString getText() const override {
        // Combine all task information into a single string
        QString taskInfo = m_text + " | Due: " + m_dueDate + " | Priority: " + m_priority + " | Label: " + m_label+ " | Location: "+m_loc;
        return taskInfo;
    }

private:
    QString m_text;
    QString m_dueDate;
    QString m_priority;
    QString m_label;
    QString m_loc;
};

#endif // TODOTASK_H
