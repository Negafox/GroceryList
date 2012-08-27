#include "ChecklistViewItem.h"
#include <QPixmap>

ChecklistViewItem::ChecklistViewItem(QWidget* parent, Checklist::Item* item) :
    QWidget(parent),
    m_completer(NULL),
    m_item(item)
{
    // Complete checkbox
    int offset = item->Depth() * 25;
    m_completeCheck = new QCheckBox(this);
    connect(m_completeCheck, SIGNAL(stateChanged(int)), this, SLOT(CompleteToggled(int)));
    m_completeCheck->setGeometry(offset,
        0,
        30,
        this->height());
    m_completeCheck->setEnabled(!m_item->Children()->count());
    m_completeCheck->setCheckState(static_cast<Qt::CheckState>(m_item->Completion()));
    
    // Name textbox
    m_entryEdit = new QLineEdit(this);
    connect(m_entryEdit, SIGNAL(textChanged(QString)), this, SLOT(NameChanged(QString)));
    m_entryEdit->setGeometry(m_completeCheck->geometry().right() + 5,
        0,
        200,
        this->height());
    m_entryEdit->setText(m_item->Name());
    
    // Add button
    m_addButton = new QPushButton(this);
    connect(m_addButton, SIGNAL(clicked()), this, SLOT(AddClick()));
    m_addButton->setGeometry(m_entryEdit->geometry().right() + 5,
        0,
        25,
        this->height());
    m_addButton->setIcon(QIcon(":/Images/Images/Add.png"));
    m_addButton->setFlat(true);
    m_addButton->setVisible(false);
    
    // Remove button
    m_removeButton = new QPushButton(this);
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(RemoveClick()));
    m_removeButton->setGeometry(m_addButton->geometry().right() + 5,
        0,
        25,
        this->height());
    m_removeButton->setIcon(QIcon(":/Images/Images/Remove.png"));
    m_removeButton->setFlat(true);
    m_removeButton->setVisible(false);
}

ChecklistViewItem::~ChecklistViewItem()
{
    // Delete our controls.
    delete m_addButton;
    m_addButton = NULL;
    
    delete m_removeButton;
    m_removeButton = NULL;
    
    delete m_completeCheck;
    m_completeCheck = NULL;
    
    delete m_entryEdit;
    m_entryEdit = NULL;
}

void ChecklistViewItem::SetAutoComplete(QStringList& list)
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

void ChecklistViewItem::enterEvent(QEvent* /*event*/)
{
    if (m_addButton)
        m_addButton->setVisible(true);
    
    if (m_removeButton)
        m_removeButton->setVisible(true);
}

void ChecklistViewItem::leaveEvent(QEvent* /*event*/)
{
    if (m_addButton)
        m_addButton->setVisible(false);
    
    if (m_removeButton)
        m_removeButton->setVisible(false);
}

void ChecklistViewItem::CompleteToggled(int state)
{
    // Sanity check.
    if (!m_item)
        return;
    
    m_item->SetCompletion(static_cast<Checklist::CompletionState>(state));
    
    // Send notification an item checkstate changed.
    emit ToggledItem();
}

void ChecklistViewItem::NameChanged(QString text)
{
    // Sanity check.
    if (!m_item)
        return;
    
    // Send notification an item was added.
    m_item->SetName(text);
}

void ChecklistViewItem::AddClick()
{
    // Sanity check.
    if (!m_item)
        return;
    
    // Create new child for this item.
    Checklist::Item* item = new Checklist::Item("[Enter Name]");
    m_item->AddChild(item);
    
    // Send notification an item was added.
    emit AddedItem();
}

void ChecklistViewItem::RemoveClick()
{
    // Sanity check.
    if (!m_item)
        return;
    
    // Remove item.
    Checklist::Item* parent = m_item->Parent();
    if (parent)
        parent->RemoveChild(m_item);
    delete m_item;
    
    // Send notification this item was removed.
    emit RemovedItem();
}