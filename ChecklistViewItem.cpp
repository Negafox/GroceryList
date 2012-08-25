#include "ChecklistViewItem.h"

ChecklistViewItem::ChecklistViewItem(QWidget *parent, Checklist::Item *item) :
    QWidget(parent),
    m_item(item)
{
    m_completeCheck = new QCheckBox(this);
    connect(m_completeCheck, SIGNAL(stateChanged(int)), this, SLOT(CompleteToggled(int)));
    m_completeCheck->setGeometry(0,
        0,
        30,
        this->height());
    m_completeCheck->setCheckState(static_cast<Qt::CheckState>(m_item->Completion()));
    m_completeCheck->show();
    
    m_entryEdit = new QLineEdit(this);
    connect(m_entryEdit, SIGNAL(textChanged(QString)), this, SLOT(NameChanged(QString)));
    m_entryEdit->setGeometry(m_completeCheck->width() + 5,
        0,
        200,
        this->height());
    m_entryEdit->setText(m_item->Name());
    m_entryEdit->show();
    
    m_removeButton = new QPushButton(this);
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(RemoveClick()));
    m_removeButton->setGeometry(m_completeCheck->width() + 5 + m_entryEdit->width() + 5,
        0,
        75,
        this->height());
    m_removeButton->setText("Remove");
    m_removeButton->setVisible(false);
}

ChecklistViewItem::~ChecklistViewItem()
{
    delete m_removeButton;
    delete m_completeCheck;
    delete m_entryEdit;
}

void ChecklistViewItem::enterEvent(QEvent* /*event*/)
{
    m_removeButton->setVisible(true);
}

void ChecklistViewItem::leaveEvent(QEvent* /*event*/)
{
    m_removeButton->setVisible(false);
}

void ChecklistViewItem::CompleteToggled(int state)
{
    m_item->SetCompletion(static_cast<Checklist::CompletionState>(state));
}

void ChecklistViewItem::NameChanged(QString text)
{
    m_item->SetName(text);
}

void ChecklistViewItem::RemoveClick()
{
}