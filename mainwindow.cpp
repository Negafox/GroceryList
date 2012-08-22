#include "mainwindow.h"
#include "ui_mainwindow.h"

void SetupDummyData(Checklist* checklist)
{
    // TEMP: Need to implement add, delete, save and load
    ChecklistItems* items = checklist->Get();
    ChecklistItem* item = new ChecklistItem(false, "Milk");
    items->push_back(item);
    item = new ChecklistItem(true, "Lucky Charms");
    items->push_back(item);
    item = new ChecklistItem(true, "Wheat Bread");
    items->push_back(item);
    item = new ChecklistItem(false, "Peanut Butter M&Ms");
    items->push_back(item);
    
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_checklist = new Checklist();
    SetupDummyData(m_checklist);
    m_view = new ChecklistView(this, m_checklist->Get());
    m_view->setGeometry(geometry());
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_view;
    delete m_ui;
}