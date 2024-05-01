// meetingtask.h
#ifndef MEETINGTASK_H
#define MEETINGTASK_H

#include "task.h"
#include <QString>

class MeetingTask : public Task {
public:
    MeetingTask(const QString &text, const QString &due, const QString &priority, const QString &location)
        : m_text(text), m_due(due), m_priority(priority), m_location(location) {}

    QString getText() const override {
        return"   "+ m_text +" | Meeting Time: "+ m_due+" Priority: "+ m_priority+ " | Location: " + m_location;
    }

private:
    QString m_text;
    QString m_location;
    QString m_due;
    QString m_priority;

};

#endif // MEETINGTASK_H
