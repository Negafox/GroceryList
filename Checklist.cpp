#include "Checklist.h"

ChecklistItem::ChecklistItem(bool complete, QString name) :
    m_complete(complete),
    m_name(name)
{
}

void ChecklistItem::SetName(QString name)
{
    m_name = name;
}

QString ChecklistItem::GetName()
{
    return m_name;
}
    
void ChecklistItem::SetComplete(bool complete)
{
    m_complete = complete;
}
    
bool ChecklistItem::GetComplete()
{
    return m_complete;
}

ChecklistItems* Checklist::Get()
{
    if (!m_items)
        m_items = new ChecklistItems();
    return m_items;
}