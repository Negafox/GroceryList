#include "ChecklistViewItem.h"

ChecklistViewItem::ChecklistViewItem(QWidget *parent, ChecklistItem *item) :
    QWidget(parent),
    m_item(item)
{
    m_completeCheck = new QCheckBox(this);
    connect(m_completeCheck, SIGNAL(stateChanged(int)), this, SLOT(CompleteToggled(int)));
    m_completeCheck->setGeometry(0,
        0,
        30,
        this->height());
    Qt::CheckState isChecked = m_item->GetComplete() ?
        Qt::Checked :
        Qt::Unchecked;
    m_completeCheck->setCheckState(isChecked);
    m_completeCheck->show();
    
    m_entryEdit = new QLineEdit(this);
    connect(m_entryEdit, SIGNAL(textChanged(QString)), this, SLOT(NameChanged(QString)));
    m_entryEdit->setGeometry(m_completeCheck->width() + 5,
        0,
        200,
        this->height());
    m_entryEdit->setText(m_item->GetName());
    m_entryEdit->show();
    
    m_removeButton = new QPushButton(this);
    connect(m_removeButton, SIGNAL(clicked()), this, SLOT(RemoveClick()));
    m_removeButton->setGeometry(m_completeCheck->width() + 5 + m_entryEdit->width() + 5,
        0,
        75,
        this->height());
    m_removeButton->setText("Remove");
    m_removeButton->show();
}

ChecklistViewItem::~ChecklistViewItem()
{
    delete m_removeButton;
    delete m_completeCheck;
    delete m_entryEdit;
}

void ChecklistViewItem::CompleteToggled(int state)
{
    m_item->SetComplete(state > 0);
}

void ChecklistViewItem::NameChanged(QString text)
{
    m_item->SetName(text);
}

void ChecklistViewItem::RemoveClick()
{
    
}