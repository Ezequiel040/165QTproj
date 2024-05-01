


// #include "seconddialog.h"
// #include "ui_seconddialog.h"

// secondDialog::secondDialog(QWidget *parent) :
//     QDialog(parent),
//     ui(new Ui::secondDialog),
//     buttonClickedCount(0)
// {
//     ui->setupUi(this);
// }

// secondDialog::~secondDialog()
// {
//     delete ui;
// }

// void secondDialog::on_taskButton_clicked()
// {
//     QString taskText = ui->taskText->text();
//     QString dueText = ui->dueText->text();
//     QString priorityText = ui->priorityText->text();
//     QString labelText = ui->labelText->text();

//     QString allText = taskText + " | Due: " + dueText + " | Priority: " + priorityText + " | Label: " + labelText;

//     emit allEntered(allText);
//     buttonClickedCount++;
//     checkButtonClickCount();

//     // Clear the line edits
//     ui->taskText->clear();
//     ui->dueText->clear();
//     ui->priorityText->clear();
//     ui->labelText->clear();

//     close();
// }

// void secondDialog::clearInputs()
// {
//     ui->taskText->clear();
//     ui->dueText->clear();
//     ui->priorityText->clear();
//     ui->labelText->clear();
// }

// void secondDialog::checkButtonClickCount()
// {
//     if (buttonClickedCount >= 4) {
//         accept();
//     }
// }

// void secondDialog::addTask(Task *task)
// {
//     m_tasks.push_back(task);
//     // Emit a signal if needed
// }
#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "todotask.h" // Include TodoTask header file
#include "meetingtask.h" // Include MeetingTask header file
#include "hometask.h" // Include HomeTask header file
#include <QDebug>

secondDialog::secondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondDialog),
    buttonClickedCount(0)
{
    ui->setupUi(this);

    // Populate the combobox with task types
    ui->taskTypeComboBox->addItem("Todo Task");
    ui->taskTypeComboBox->addItem("Meeting Task");
    ui->taskTypeComboBox->addItem("Home Task");
}

secondDialog::~secondDialog()
{
    delete ui;
}

void secondDialog::on_taskButton_clicked()
{
    QString taskText = ui->taskText->text();
    QString dueText = ui->dueText->text();
    QString priorityText = ui->priorityText->text();
    QString labelText = ui->labelText->text();
    QString locText = ui->locationText->text();

    // Determine the selected task type
    QString taskType = ui->taskTypeComboBox->currentText();
    emit allEntered(taskText, dueText, priorityText, labelText, locText);

    // Create a Task object based on the selected task type
    Task *task = nullptr;
    if (taskType == "Todo Task") {
        task = new TodoTask(taskText, dueText, priorityText, labelText,locText);
    } else if (taskType == "Meeting Task") {
        task = new MeetingTask(taskText,dueText,priorityText ,locText);
    } else if (taskType == "Home Task") {
        task = new HomeTask(taskText, dueText, locText); // You need to pass appropriate parameters
    }

    if (task) {
        // Add the task to the list
        addTask(task);

        // Emit a signal with task information
        //emit allEntered(taskText, dueText, priorityText, labelText, locText);

        // Increment button click count and check if it's reached the limit
        buttonClickedCount++;
        checkButtonClickCount();

        // Clear the line edits
        ui->taskText->clear();
        ui->dueText->clear();
        ui->priorityText->clear();
        ui->labelText->clear();
        ui->locationText->clear();

        // Close the dialog
        close();
    } else {
        qDebug() << "Failed to create task. Task type not recognized.";
    }
}

void secondDialog::clearInputs()
{
    ui->taskText->clear();
    ui->dueText->clear();
    ui->priorityText->clear();
    ui->labelText->clear();
    ui->locationText->clear();
}

void secondDialog::checkButtonClickCount()
{
    if (buttonClickedCount >= 4) {
        accept();
    }
}

void secondDialog::addTask(Task *task)
{
    qDebug() << "Task : " << task->getText();

    m_tasks.push_back(task);

    // Emit a signal if needed
}
QString secondDialog::getSelectedTaskType() const {
    return ui->taskTypeComboBox->currentText();
}
