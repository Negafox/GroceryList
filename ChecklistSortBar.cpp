#include "ChecklistSortBar.h"

ChecklistSortBar::ChecklistSortBar(QWidget* parent, Checklist::Items* items) :
    QWidget(parent),
    m_items(items),
    m_sortOrder(CompleteSortUp)
{
    // Complete sort button
    m_completeSortButton = new QPushButton(this);
    connect(m_completeSortButton, SIGNAL(clicked()), this, SLOT(CompleteSortClick()));
    m_completeSortButton->setGeometry(0,
        0,
        25,
        this->height());
    m_completeSortButton->setIcon(QIcon(":/Images/Images/Add.png"));
    m_completeSortButton->setFlat(true);
    m_completeSortButton->setVisible(true);
    
    // Name sort button
    m_nameSortButton = new QPushButton(this);
    connect(m_nameSortButton, SIGNAL(clicked()), this, SLOT(NameSortClick()));
    m_nameSortButton->setGeometry(m_completeSortButton->geometry().right() + 5,
        0,
        25,
        this->height());
    m_nameSortButton->setIcon(QIcon(":/Images/Images/Add.png"));
    m_nameSortButton->setFlat(true);
    m_nameSortButton->setVisible(true);
}

ChecklistSortBar::~ChecklistSortBar()
{
    // Delete our controls.    
    delete m_completeSortButton;
    m_completeSortButton = NULL;
    
    delete m_nameSortButton;
    m_nameSortButton = NULL;
}

bool ChecklistSortBar::SortByCompleteUp(Checklist::Item* a, Checklist::Item* b)
{
    return a->Completion() > b->Completion();
}

bool ChecklistSortBar::SortByCompleteDown(Checklist::Item* a, Checklist::Item* b)
{
    return a->Completion() < b->Completion();
}

bool ChecklistSortBar::SortByNameUp(Checklist::Item* a, Checklist::Item* b)
{
    return a->Name() > b->Name();
}

bool ChecklistSortBar::SortByNameDown(Checklist::Item* a, Checklist::Item* b)
{
    return a->Name() < b->Name();
}

void ChecklistSortBar::CompleteSortClick()
{
    // Sanity check.
    if (!m_items)
        return;
    
    if (m_sortOrder == CompleteSortUp)
    {
        std::sort(m_items->begin(), m_items->end(), SortByCompleteDown);
        m_sortOrder = CompleteSortDown;
    }
    else
    {
        std::sort(m_items->begin(), m_items->end(), SortByCompleteUp);
        m_sortOrder = CompleteSortUp;
    }
    
    // Send notification that the sorting changed.
    emit SortChanged();
}

void ChecklistSortBar::NameSortClick()
{
    // Sanity check.
    if (!m_items)
        return;
    
    if (m_sortOrder == NameSortUp)
    {
        std::sort(m_items->begin(), m_items->end(), SortByNameDown);
        m_sortOrder = NameSortDown;
    }
    else
    {
        std::sort(m_items->begin(), m_items->end(), SortByNameUp);
        m_sortOrder = NameSortUp;
    }
    
    // Send notification that the sorting changed.
    emit SortChanged();
}
