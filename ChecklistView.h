#ifndef GroceryList_ChecklistView_h
#define GroceryList_ChecklistView_h

#include "ChecklistSortbar.h"
#include "ChecklistViewItem.h"
#include "ChecklistViewNewItem.h"
#include "Checklist.h"

typedef QList<ChecklistViewItem*> ChecklistViewItems;

class ChecklistView : public QWidget
{
Q_OBJECT
    
public:
    ChecklistView(QWidget *parent = 0, Checklist::Items *items = 0);
    ~ChecklistView();
    
    void Clear();
    
public slots:
    void Refresh();
    
private:
    void resizeEvent(QResizeEvent* event);
    void GenerateViewItems(Checklist::Items* items);
    
    Checklist::Items* m_items;
    ChecklistSortBar *m_sortBar;
    ChecklistViewItems m_viewItems;
    ChecklistViewNewItem* m_viewNewItem;
    
    QStringList m_suggestionList;
};

#endif
