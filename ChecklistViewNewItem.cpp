#include "ChecklistViewNewItem.h"

ChecklistViewNewItem::ChecklistViewNewItem(QWidget* parent, Checklist::Items* items) :
    QWidget(parent),
    m_completer(NULL),
    m_items(items)
{
    // Name textbox
    m_entryEdit = new QLineEdit(this);
    m_entryEdit->setGeometry(35,
        0,
        200,
        this->height());
    m_entryEdit->setText("[Enter Name]");
    
    // Add button
    m_addButton = new QPushButton(this);
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(AddClick()));
    m_addButton->setGeometry(m_entryEdit->geometry().right() + 5,
        0,
        25,
        this->height());
    m_addButton->setIcon(QIcon(":/Images/Images/Add.png"));
    m_addButton->setFlat(true);
    m_addButton->setVisible(true);
}

ChecklistViewNewItem::~ChecklistViewNewItem()
{
    // Delete our controls.    
    delete m_entryEdit;
    m_entryEdit = NULL;
    
    delete m_addButton;
    m_addButton = NULL;
}

void ChecklistViewNewItem::SetAutoComplete(QStringList& list)
{
    if (m_completer)
    {
        m_entryEdit->setCompleter(NULL);
        
        delete m_completer;
        m_completer = NULL;
    }
    
    if (!list.empty())
    {
        m_completer = new QCompleter(list, this);
        m_completer->setCaseSensitivity(Qt::CaseInsensitive);
        m_entryEdit->setCompleter(m_completer);
    }
}

void ChecklistViewNewItem::AddClick()
{
    // Sanity check.
    if (!m_items)
        return;
    
    // Create new child for this item.
    Checklist::Item* item = new Checklist::Item(m_entryEdit->text());
    m_items->push_back(item);
    
    // Reset text.
    m_entryEdit->setText("[Enter Name]");
    
    // Send notification an item was added.
    emit AddedItem();
}