#ifndef GroceryList_ChecklistViewNewItem_h
#define GroceryList_ChecklistViewNewItem_h

#include <QPushButton>
#include <QLineEdit>
#include "Checklist.h"

class ChecklistViewNewItem : public QWidget
{
    Q_OBJECT
    
public:
    ChecklistViewNewItem(QWidget *parent = 0, Checklist::Items* items = 0);
    ~ChecklistViewNewItem();
    
public slots:
    void AddClick();
    
signals:
    void AddedItem();
    
private:
    QLineEdit* m_entryEdit;
    QPushButton* m_addButton;
    
    Checklist::Items* m_items;
};

#endif
