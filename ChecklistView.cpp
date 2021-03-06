#include "ChecklistView.h"

void GenerateSuggestionList(QStringList& list)
{
    list << "Chicken";
    list << "Beef";
    list << "Rice";
    list << "Beans";
    list << "Cereal";
    list << "Soda";
}

ChecklistView::ChecklistView(QWidget* parent, Checklist::Items* items) :
    QWidget(parent),
    m_items(items)
{
    // TEMP: Generate hardcoded suggestion list.
    GenerateSuggestionList(m_suggestionList);
    
    // Create sort bar.
    m_sortBar = new ChecklistSortBar(this, items);
    m_sortBar->setGeometry(0, 0, this->width(), 30);
    m_sortBar->setVisible(true);
    QObject::connect(m_sortBar, SIGNAL(SortChanged()), this, SLOT(Refresh()));
    
    // Create new checklist item widget.
    m_viewNewItem = new ChecklistViewNewItem(this, items);
    m_viewNewItem->setVisible(true);
    m_viewNewItem->SetAutoComplete(m_suggestionList);
    QObject::connect(m_viewNewItem, SIGNAL(AddedItem()), this, SLOT(Refresh()));
    
    // Generate the checklist widgets.
    Refresh();
}

ChecklistView::~ChecklistView()
{
    Clear();
    delete m_viewNewItem;
}

void ChecklistView::Clear()
{
    for (ChecklistViewItems::size_type i = 0; i < m_viewItems.count(); ++i)
    {
        delete m_viewItems[i];
    }
    m_viewItems.clear();
}

void ChecklistView::GenerateViewItems(Checklist::Items* items)
{
    for (Checklist::Items::size_type i = 0; i < items->count(); ++i)
    {
        // Add this item.
        ChecklistViewItem* viewItem = new ChecklistViewItem(this, (*items)[i]);
        viewItem->setGeometry(0, (m_viewItems.count() + 1) * 35, this->width(), 30);
        viewItem->setVisible(true);
        viewItem->SetAutoComplete(m_suggestionList);
        QObject::connect(viewItem, SIGNAL(ToggledItem()), this, SLOT(Refresh()));
        QObject::connect(viewItem, SIGNAL(AddedItem()), this, SLOT(Refresh()));
        QObject::connect(viewItem, SIGNAL(RemovedItem()), this, SLOT(Refresh()));
        m_viewItems.push_back(viewItem);
        
        // Add the children as well.
        if ((*items)[i]->Children()->count())
            GenerateViewItems((*items)[i]->Children());
    }
}

void ChecklistView::Refresh()
{
    Clear();
    GenerateViewItems(m_items);
    m_viewNewItem->setGeometry(0, (m_viewItems.count() + 1) * 35, 400, 30);
    
}

void ChecklistView::resizeEvent(QResizeEvent* event)
{
    this->QWidget::resizeEvent(event);
    for (ChecklistViewItems::iterator viewItem = m_viewItems.begin(); viewItem != m_viewItems.end(); ++viewItem)
    {
        ChecklistViewItem* item = *viewItem;
        QRect rect(item->geometry());
        rect.setWidth(this->width());
        item->setGeometry(rect);
    }
}