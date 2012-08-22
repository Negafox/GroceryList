#ifndef GroceryList_Checklist_h
#define GroceryList_Checklist_h

#include <QString>
#include <QList>

class ChecklistItem
{
public:
    ChecklistItem(bool complete = false, QString name = QString());

    void SetName(QString name);
    QString GetName();
    
    void SetComplete(bool complete);
    bool GetComplete();
    
private:
    bool m_complete;
    QString m_name;
};

typedef QList<ChecklistItem*> ChecklistItems;

class Checklist
{
public:
    ChecklistItems* Get();
    
private:
    ChecklistItems* m_items; 
};

#endif