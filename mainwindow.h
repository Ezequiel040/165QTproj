
// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QStandardPaths>
// #include "seconddialog.h" // Include secondDialog header file
// #include "task.h"
// #include "todotask.h"

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// public slots:
//     void addTask(Task *task);

// private slots:
//     // void on_btnAdd_clicked();
//     void on_btnRemove_clicked();
//     void on_btnRemoveAll_clicked();
//     void on_pushButton_clicked();
//     void addAllText(const QString &allText);

// private:
//     Ui::MainWindow *ui;
//     secondDialog secDialog; // Declare secDialog as a member variable
//     QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/toDoFile.txt";
//     QVector<Task*> m_tasks; // Store pointers to Task objects
// };

// #endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QListWidgetItem>
#include "seconddialog.h" // Include secondDialog header file
#include "task.h"
#include <QFile>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addTask(Task *task);

private slots:
    void on_btnRemove_clicked();
    void on_btnRemoveAll_clicked();
    void on_pushButton_clicked();
    // void addAllText(const QString &allText);
    void addAllText(const QString &taskText, const QString &dueText, const QString &priorityText, const QString &labelText, const QString &locText);
private:
    Ui::MainWindow *ui;
    secondDialog secDialog; // Declare secDialog as a member variable
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/toDoFile.txt";
    QVector<Task*> m_tasks; // Store pointers to Task objects
};

#endif // MAINWINDOW_H
