#ifndef GroceryList_ChecklistView_h
#define GroceryList_ChecklistView_h

#include "ChecklistViewItem.h"
#include "Checklist.h"

typedef QList<ChecklistViewItem*> ChecklistViewItems;

class ChecklistView : public QWidget
{
Q_OBJECT
    
public:
    ChecklistView(QWidget *parent = 0, Checklist::Items *items = 0);
    ~ChecklistView();
    
private:
    void resizeEvent(QResizeEvent* event);
    
    Checklist::Items* m_items;
    ChecklistViewItems m_viewItems;
};

#endif
