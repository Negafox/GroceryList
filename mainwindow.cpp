#include "mainwindow.h"
#include "ui_mainwindow.h"

void SetupDummyData(Checklist::List* checklist)
{
    // TEMP: Need to implement add, delete, save and load
    Checklist::Items* items = checklist->Get();
    Checklist::Item* item = new Checklist::Item("Milk");
    items->push_back(item);
    item = new Checklist::Item("Lucky Charms", Checklist::Complete);
    items->push_back(item);
    item = new Checklist::Item("Wheat Bread", Checklist::Complete);
    items->push_back(item);
    item = new Checklist::Item("Peanut Butter M&Ms");
    items->push_back(item);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_checklist = new Checklist::List();
    SetupDummyData(m_checklist);
    m_view = new ChecklistView(this, m_checklist->Get());
    m_view->setGeometry(geometry());
    setWindowTitle("Grocery List");
    setMinimumSize(320, 240);
}

MainWindow::~MainWindow()
{
    delete m_view;
    delete m_ui;
}