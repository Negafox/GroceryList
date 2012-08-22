#include "ChecklistView.h"

ChecklistView::ChecklistView(QWidget *parent, ChecklistItems *items) :
    QWidget(parent),
    m_items(items)
{
    for (ChecklistItems::size_type i = 0; i < items->count(); ++i)
    {
        ChecklistViewItem* viewItem = new ChecklistViewItem(this, (*items)[i]);
        viewItem->setGeometry(0, i * 35, this->width(), 30);
        m_viewItems.push_back(viewItem);
    }
}

ChecklistView::~ChecklistView()
{
    for (ChecklistViewItems::size_type i = 0; i < m_viewItems.count(); ++i)
    {
        delete m_viewItems[i];
    }
    m_viewItems.clear();
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