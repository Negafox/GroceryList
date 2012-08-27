#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_checklist = new Checklist::List();
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