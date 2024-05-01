#ifndef TODOLISTAPP_H
#define TODOLISTAPP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QStringList>

// Define a Task class to represent individual tasks
class Task {
public:
    Task(const QString& name, const QString& dueDate, int priority, const QStringList& labels)
        : name(name), dueDate(dueDate), priority(priority), labels(labels) {}

    QString getName() const { return name; }
    QString getDueDate() const { return dueDate; }
    int getPriority() const { return priority; }
    QStringList getLabels() const { return labels; }

private:
    QString name;
    QString dueDate;
    int priority;
    QStringList labels;
};

// Define a ToDoListApp class which manages the GUI and the backend logic
class ToDoListApp : public QWidget {
    Q_OBJECT
public:
    ToDoListApp(QWidget* parent = nullptr);

private slots:
    void addTask();

private:
    QVBoxLayout* layout;
    QLineEdit* nameLineEdit;
    QLineEdit* dueDateLineEdit;
    QLineEdit* priorityLineEdit;
    QLineEdit* labelsLineEdit;
    QPushButton* addButton;
    QListWidget* taskListWidget;
    QList<Task*> tasks;

    void setupUI();
};

#endif // TODOLISTAPP_H
