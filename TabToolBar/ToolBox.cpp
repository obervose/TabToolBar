#include "ToolBox.h"
using namespace VQS;


ToolBox::ToolBox(QWidget *parent /*= nullptr*/)
	: QFrame(parent)
	, _cpation("ÏÔÊ¾±êÌâ")
{
	initBox();
}

ToolBox::ToolBox(const QString& caption, QWidget *parent/*= nullptr*/)
	: QFrame(parent)
	, _cpation(caption)
{
	initBox();
}

ToolBox::~ToolBox()
{
}

void ToolBox::initBox()
{
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
	_pSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding);
	QVBoxLayout* _pLayoutV = new QVBoxLayout;
	_pLayoutV->setContentsMargins(6, 0, 0, 6);
	_pLayout = new QHBoxLayout;
	_pLayout->setContentsMargins(6, 0, 0, 6);
	_pLayout->setMargin(0);
	_pLayout->addSpacerItem(_pSpacer);
	_pLayoutV->addLayout(_pLayout);

	_pLabelCaption = new QLabel(_cpation);
	_pLabelCaption->setObjectName("ToolBoxCaptionLabel");
	_pLabelCaption->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	_pLabelCaption->setAlignment(Qt::AlignCenter);
	_pLabelCaption->setFixedHeight(20);
	_pLayoutV->addWidget(_pLabelCaption);
	this->setLayout(_pLayoutV);
}

void ToolBox::setCaption(const QString &str)
{
	_cpation = str;
}

QString ToolBox::caption()
{
	return _cpation;
}

void ToolBox::addToolAction(QWidget* act)
{
	_pLayout->removeItem(_pSpacer);
	auto item = dynamic_cast<QToolButton*>(act);
	if (item)
	{
		item->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		item->setIconSize(QSize(50, 50));
	}

	_pLayout->addWidget(act);
	_pLayout->addSpacerItem(_pSpacer);
}

void ToolBox::addToolActions(QList<QWidget*> &list)
{
	_pLayout->removeItem(_pSpacer);
	QVBoxLayout* pLayoutV = new QVBoxLayout;
	pLayoutV->setSpacing(2);
	pLayoutV->setContentsMargins(0, 0, 0, 0);
	pLayoutV->setMargin(0);
	for (int index = 0;index < (list.size() > 3 ? 3:list.size());++index)
	{
		auto var = list.at(index);
		auto item = dynamic_cast<QToolButton*>(var);
		if (item)
		{
			item->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		}
		pLayoutV->addWidget(var);
	}
	_pLayout->addLayout(pLayoutV);
	_pLayout->addSpacerItem(_pSpacer);
}


void ToolBox::addSeparator()
{
	//_pLayout->removeItem(_pSpacer);
	QGridLayout* pLayoutLine = new QGridLayout;
	pLayoutLine->setContentsMargins(0, 9, 0, 9);
	auto pLine = new QFrame;
	pLine->setLineWidth(10);
	pLine->setMidLineWidth(10);
	pLine->setObjectName("SeparatorLine");
	pLine->setFrameShape(QFrame::VLine);
	pLine->setFrameShadow(QFrame::Plain);
	pLayoutLine->addWidget(pLine);
	_pLayout->addLayout(pLayoutLine);
//	_pLayout->addSpacerItem(_pSpacer);
}
