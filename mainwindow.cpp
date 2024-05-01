
// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <QFile>
// #include <QMessageBox>
// #include "task.h"
// #include "todotask.h"

// MainWindow::MainWindow(QWidget *parent) :
//     QMainWindow(parent),
//     ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
//     connect(&secDialog, &secondDialog::allEntered, this, &MainWindow::addAllText);

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream in(&file);

//     while (!in.atEnd()) {
//         QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
//         ui->listWidget->addItem(item);
//         item->setFlags(item->flags() | Qt::ItemIsEditable);
//     }

//     file.close();
// }

// MainWindow::~MainWindow()
// {
//     delete ui;

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream out(&file);
//     for (int i = 0; i < ui->listWidget->count(); ++i) {
//         out << ui->listWidget->item(i)->text() << "\n";
//     }

//     file.close();
// }

// void MainWindow::on_btnRemove_clicked()
// {
//     QListWidgetItem* item = ui->listWidget->currentItem();
//     if (!item) {
//         return;
//     }
//     QString taskText = item->text();
//     delete item;

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//         return;
//     }

//     QTextStream in(&file);
//     QStringList lines;
//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         if (line != taskText) {
//             lines.append(line);
//         }
//     }

//     file.resize(0);

//     QTextStream out(&file);
//     for (const QString& line : lines) {
//         out << line << "\n";
//     }

//     file.close();
// }


// void MainWindow::on_btnRemoveAll_clicked()
// {
//     // Clear the QListWidget
//     ui->listWidget->clear();

//     // Open the file in WriteOnly mode to clear its content
//     QFile file(path);
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         QMessageBox::information(0, "Error", file.errorString());
//         return;
//     }

//     // Close the file
//     file.close();
// }


// void MainWindow::on_pushButton_clicked()
// {
//     secDialog.setModal(true);
//     secDialog.exec();
// }

// void MainWindow::addAllText(const QString &allText) {
//     QListWidgetItem* item = new QListWidgetItem(allText, ui->listWidget);
// }

// void MainWindow::addTask(Task *task)
// {
//     m_tasks.push_back(task);
//     QListWidgetItem* item = new QListWidgetItem(task->getText(), ui->listWidget);
//     ui->listWidget->addItem(item);
//     item->setFlags(item->flags() | Qt::ItemIsEditable);
// }
















// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include <QFile>
// #include <QMessageBox>
// #include "hometask.h" // Include HomeTask header file
// #include "meetingtask.h" // Include MeetingTask header file

// MainWindow::MainWindow(QWidget *parent) :
//     QMainWindow(parent),
//     ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
//     connect(&secDialog, &secondDialog::allEntered, this, &MainWindow::addAllText);

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream in(&file);

//     while (!in.atEnd()) {
//         QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
//         ui->listWidget->addItem(item);
//         item->setFlags(item->flags() | Qt::ItemIsEditable);
//     }

//     file.close();
// }

// MainWindow::~MainWindow()
// {
//     delete ui;

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//     }

//     QTextStream out(&file);
//     for (int i = 0; i < ui->listWidget->count(); ++i) {
//         out << ui->listWidget->item(i)->text() << "\n";
//     }

//     file.close();
// }

// void MainWindow::on_btnRemove_clicked()
// {
//     QListWidgetItem* item = ui->listWidget->currentItem();
//     if (!item) {
//         return;
//     }
//     QString taskText = item->text();
//     delete item;

//     QFile file(path);
//     if (!file.open(QIODevice::ReadWrite)) {
//         QMessageBox::information(0, "error", file.errorString());
//         return;
//     }

//     QTextStream in(&file);
//     QStringList lines;
//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         if (line != taskText) {
//             lines.append(line);
//         }
//     }

//     file.resize(0);

//     QTextStream out(&file);
//     for (const QString& line : lines) {
//         out << line << "\n";
//     }

//     file.close();
// }


// void MainWindow::on_btnRemoveAll_clicked()
// {
//     // Clear the QListWidget
//     ui->listWidget->clear();

//     // Open the file in WriteOnly mode to clear its content
//     QFile file(path);
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         QMessageBox::information(0, "Error", file.errorString());
//         return;
//     }

//     // Close the file
//     file.close();
// }


// void MainWindow::on_pushButton_clicked()
// {
//     secDialog.setModal(true);
//     secDialog.exec();
// }

// void MainWindow::addAllText(const QString &allText) {
//     QListWidgetItem* item = new QListWidgetItem(allText, ui->listWidget);
// }

// void MainWindow::addTask(Task *task)
// {
//     m_tasks.push_back(task);
//     QListWidgetItem* item = new QListWidgetItem(task->getText(), ui->listWidget);
//     ui->listWidget->addItem(item);
//     item->setFlags(item->flags() | Qt::ItemIsEditable);
// }


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include"hometask.h"
#include "task.h" // Include the header file for Task if used
#include "todotask.h" // Include the header file for TodoTask if used
#include "seconddialog.h"
#include "meetingtask.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&secDialog, &secondDialog::allEntered, this, &MainWindow::addAllText);

    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;

    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << "\n";
    }

    file.close();
}

void MainWindow::addTask(Task *task)
{
    m_tasks.push_back(task);
    QListWidgetItem* item = new QListWidgetItem(task->getText(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (!item) {
        return;
    }
    QString taskText = item->text();
    delete item;

    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line != taskText) {
            lines.append(line);
        }
    }

    file.resize(0);

    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << "\n";
    }

    file.close();
}

void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear();

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(0, "Error", file.errorString());
        return;
    }

    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    secDialog.setModal(true);
    secDialog.exec();
}

// void MainWindow::addAllText(const QString &taskText, const QString &dueText, const QString &priorityText, const QString &labelText, const QString &locText) {
//     QString allText = taskText + " | Due: " + dueText + " | Priority: " + priorityText + " | Label: " + labelText + " | Location: " + locText;
//     QListWidgetItem* item = new QListWidgetItem(allText, ui->listWidget);
// }
void MainWindow::addAllText(const QString &taskText, const QString &dueText, const QString &priorityText, const QString &labelText, const QString &locText) {
    QString allText;
    QString taskType = secDialog.getSelectedTaskType();

    if (taskType == "Todo Task") {
        // allText ="Todo: "+ taskText + " | Due: " + dueText + " | Priority: " + priorityText + " | Label: " + labelText + " | Location: " + locText;
         TodoTask TodoTask(taskText,dueText,priorityText,labelText,locText ); // Assuming you have necessary constructors
         allText = TodoTask.getText();
    } else if (taskType == "Meeting Task") {
        // allText ="Meeting: "+ taskText + " | Meeting Time: " + dueText + " | Priority: " + priorityText + " | Location: " + locText;
        MeetingTask meetingTask(taskText,dueText,priorityText ,locText); // Assuming you have necessary constructors
        allText = meetingTask.getText();
    } else if (taskType == "Home Task") {
        // allText ="Home: "+ taskText + " | Due: " + dueText + " | Label: " + labelText;
        HomeTask HomeTask(taskText,dueText ,labelText); // Assuming you have necessary constructors
        allText = HomeTask.getText();
    }

    QListWidgetItem* item = new QListWidgetItem(allText, ui->listWidget);
}
