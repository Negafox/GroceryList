#include "Checklist.h"

namespace Checklist
{

Item::Item(QString name, CompletionState completion, Item* parent) :
    m_name(name),
    m_completion(completion),
    m_parent(parent),
    m_items(new QList<Item*>())
{
}
    
Item::~Item()
{
    delete m_items;
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
    Refresh();
}
    
CompletionState Item::Completion()
{
    return m_completion;
}

QList<Item*>* Item::Children()
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

int Item::DepthInternal(Item* item, int index)
{
    if (item->Parent())
        DepthInternal(item->Parent(), ++index);
    return index;
}
    
int Item::Depth()
{
    if (m_parent)
        return DepthInternal(m_parent, 1);
    else
        return 0;
}
    
void Item::AddChild(Item* item)
{
    item->SetParent(this);
    m_items->push_back(item);
    Refresh();
}
    
void Item::RemoveChild(Item* item)
{
    item->SetParent(NULL);
    int index = m_items->indexOf(item);
    m_items->erase(m_items->begin() + index);
    Refresh();
}
    
void Item::Refresh()
{
    // Update completion state based upon children, if necessary.
    if (!m_items->empty())
    {
        m_completion = (*m_items)[0]->Completion();
        for (QList<Item*>::Iterator item = ++m_items->begin(); item != m_items->end(); ++item)
        {
            if ((*item)->Completion() == Partial || (*item)->Completion() != m_completion)
            {
                m_completion = Partial;
                break;
            }
        }
    }
    else if (m_completion == Partial)
        m_completion = Complete;
    
    // Update parent as well.
    if (m_parent)
        m_parent->Refresh();
}

Items* List::Get()
{
    if (!m_items)
        m_items = new Items();
    return m_items;
}

};