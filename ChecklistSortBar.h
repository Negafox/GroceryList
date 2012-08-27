#ifndef GroceryList_ChecklistSortBar_h
#define GroceryList_ChecklistSortBar_h

#include <QPushButton>
#include "Checklist.h"

enum ChecklistSort
{
    CompleteSortUp = 0,
    CompleteSortDown,
    NameSortUp,
    NameSortDown
};

class ChecklistSortBar : public QWidget
{
    Q_OBJECT
    
public:
    ChecklistSortBar(QWidget *parent = 0, Checklist::Items* items = 0);
    ~ChecklistSortBar();
    
public slots:
    void CompleteSortClick();
    void NameSortClick();
    
signals:
    void SortChanged();
    
private:
    static bool SortByCompleteUp(Checklist::Item* a, Checklist::Item* b);
    static bool SortByCompleteDown(Checklist::Item* a, Checklist::Item* b);
    static bool SortByNameUp(Checklist::Item* a, Checklist::Item* b);
    static bool SortByNameDown(Checklist::Item* a, Checklist::Item* b);
    
    QPushButton* m_completeSortButton;
    QPushButton* m_nameSortButton;
    
    Checklist::Items* m_items;
    ChecklistSort m_sortOrder;
};

#endif
