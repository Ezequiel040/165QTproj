
// #ifndef SECONDDIALOG_H
// #define SECONDDIALOG_H

// #include <QDialog>
// #include "task.h"
// #include "task.h"

// QT_BEGIN_NAMESPACE
// namespace Ui { class secondDialog; }
// QT_END_NAMESPACE

// class secondDialog : public QDialog
// {
//     Q_OBJECT

// public:
//     explicit secondDialog(QWidget *parent = nullptr);
//     ~secondDialog();
//     void clearInputs(); // Declaration of the clearInputs method

// public slots:
//     void addTask(Task *task);

// signals:
//     void allEntered(const QString &allText);

// private slots:
//     void on_taskButton_clicked();
//     // void on_dueButton_clicked();
//     // void on_priorityButton_clicked();
//     // void on_labelButton_2_clicked();

//     void checkButtonClickCount(); // Declaration of the checkButtonClickCount method

// private:
//     Ui::secondDialog *ui;
//     int buttonClickedCount; // Declaration of the buttonClickedCount variable
//     QVector<Task*> m_tasks; // Store pointers to Task objects
// };

// #endif // SECONDDIALOG_H

#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>
#include <QVector>  // Include QVector header if not already included
#include "task.h"  // Include Task header if not already included

namespace Ui {
class secondDialog;
}

class secondDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondDialog(QWidget *parent = nullptr);
    ~secondDialog();
    void clearInputs();
    QString getSelectedTaskType() const;

signals:
    void allEntered(const QString &taskText, const QString &dueText, const QString &priorityText, const QString &labelText, const QString &locText);

private slots:
    void on_taskButton_clicked();
    void checkButtonClickCount();
    void addTask(Task *task);  // Add declaration for addTask function

private:
    Ui::secondDialog *ui;
    int buttonClickedCount;
    QVector<Task*> m_tasks;  // Declare m_tasks as a QVector member variable
};

#endif // SECONDDIALOG_H
