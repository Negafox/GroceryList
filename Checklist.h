#ifndef GroceryList_Checklist_h
#define GroceryList_Checklist_h

#include <QString>
#include <QList>

namespace Checklist
{
    
enum CompletionState
{
    Incomplete = 0,
    Partial = 1,
    Complete = 2
};

class Item
{
public:
    Item(QString name = QString(), CompletionState completion = Incomplete, Item* parent = NULL);
    ~Item();

    void SetName(QString name);
    QString Name();
    
    void SetCompletion(CompletionState completion);
    CompletionState Completion();
    
    void SetParent(Item* parent);
    Item* Parent();
    
    int Depth();
    
    void AddChild(Item* child);
    void RemoveChild(Item* child);
    QList<Item*>* Children();
    
    void Refresh();
    
private:
    int DepthInternal(Item* item, int index);
    
    QString m_name;
    CompletionState m_completion;
    Item* m_parent;
    QList<Item*>* m_items;
};
    
typedef QList<Item*> Items;

class List
{
public:
    Items* Get();
    
private:
    Items* m_items; 
};
    
};

#endif