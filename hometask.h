// hometask.h
#ifndef HOMETASK_H
#define HOMETASK_H

#include "task.h"
#include <QString>

class HomeTask : public Task {
public:
    HomeTask(const QString &text, const QString &dueDate, const QString &location)
        : m_text(text), m_dueDate(dueDate), m_location(location) {}

    QString getText() const override {
        // Combine all task information into a single string
        QString taskInfo = m_text + " | Due: " + m_dueDate + " | Location: " + m_location;
        return taskInfo;
    }

private:
    QString m_text;
    QString m_dueDate;
    QString m_location;
};

#endif // HOMETASK_H
