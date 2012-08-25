#ifndef GroceryList_ChecklistViewItem_h
#define GroceryList_ChecklistViewItem_h

#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include "Checklist.h"

class ChecklistViewItem : public QWidget
{
    Q_OBJECT
    
public:
    ChecklistViewItem(QWidget *parent = 0, Checklist::Item *item = 0);
    ~ChecklistViewItem();

public slots:
    void CompleteToggled(int state);
    void NameChanged(QString text);
    void RemoveClick();
    
private:
    QCheckBox* m_completeCheck;
    QLineEdit* m_entryEdit;
    QPushButton* m_removeButton;
    
    Checklist::Item* m_item;
    
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
};

#endif
