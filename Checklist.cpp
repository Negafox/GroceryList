#include "Checklist.h"

namespace Checklist
{

Item::Item(QString name, CompletionState completion, Item* parent) :
    m_name(name),
    m_completion(completion),
    m_parent(parent)
{
}

void Item::SetName(QString name)
{
    m_name = name;
}

QString Item::Name()
{
    return m_name;
}
    
void Item::SetCompletion(CompletionState completion)
{
    m_completion = completion;
}
    
CompletionState Item::Completion()
{
    return m_completion;
}

QList<Item*> Item::Children()
{
    return m_items;
}
    
void Item::SetParent(Item* parent)
{
    m_parent = parent;
}
    
Item* Item::Parent()
{
    return m_parent;
}
    
void Item::Refresh()
{
    if (!m_items.empty())
    {
        CompletionState completion = m_items[0]->Completion();
        for (QList<Item*>::Iterator item = ++m_items.begin(); item != m_items.end(); ++item)
        {
            if ((*item)->Completion() == Partial || (*item)->Completion() != completion)
            {
                m_completion = Partial;
                return;
            }
        }
    }
}

Items* List::Get()
{
    if (!m_items)
        m_items = new Items();
    return m_items;
}

};