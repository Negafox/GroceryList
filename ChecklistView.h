#ifndef GroceryList_ChecklistView_h
#define GroceryList_ChecklistView_h

#include "ChecklistViewItem.h"
#include "Checklist.h"

typedef QList<ChecklistViewItem*> ChecklistViewItems;

class ChecklistView : public QWidget
{
Q_OBJECT
    
public:
    ChecklistView(QWidget *parent = 0, ChecklistItems *items = 0);
    ~ChecklistView();
    
private:
    void resizeEvent(QResizeEvent* event);
    
    ChecklistItems* m_items;
    ChecklistViewItems m_viewItems;
};

#endif
