#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Checklist.h"
#include "ChecklistViewItem.h"
#include "ChecklistView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *m_ui;
    ChecklistView *m_view;
    
    Checklist::List *m_checklist;
};

#endif // MAINWINDOW_H
