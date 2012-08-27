#ifndef GroceryList_ChecklistViewNewItem_h
#define GroceryList_ChecklistViewNewItem_h

#include <QCompleter>
#include <QPushButton>
#include <QLineEdit>
#include "Checklist.h"

class ChecklistViewNewItem : public QWidget
{
    Q_OBJECT
    
public:
    ChecklistViewNewItem(QWidget *parent = 0, Checklist::Items* items = 0);
    ~ChecklistViewNewItem();
    
    void SetAutoComplete(QStringList& list);
    
public slots:
    void AddClick();
    
signals:
    void AddedItem();
    
private:
    QCompleter* m_completer;
    QLineEdit* m_entryEdit;
    QPushButton* m_addButton;
    
    Checklist::Items* m_items;
};

#endif
