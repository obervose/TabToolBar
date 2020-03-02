#include "TabToolPanel.h"
using namespace VQS;


TabToolPanel::TabToolPanel(QWidget *parent)
	: QFrame(parent)
{
	_pSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Expanding);
	_pLayout = new QHBoxLayout;
	_pLayout->setContentsMargins(0, 0, 0, 0);
	_pLayout->setMargin(0);
	_pLayout->addSpacerItem(_pSpacer);
	this->setLayout(_pLayout);
}

TabToolPanel::~TabToolPanel()
{
}

void TabToolPanel::addPanelBox(QString str)
{
	_pLayout->removeItem(_pSpacer);
	auto pFrame = new ToolBox();
	pFrame->setCaption(str);
	_pLayout->addWidget(pFrame);
	_pLayout->addItem(_pSpacer);
}

void TabToolPanel::addPanelBox(ToolBox* box)
{
	_pLayout->removeItem(_pSpacer);
	_pLayout->addWidget(box);
	_pLayout->addItem(_pSpacer);
}

void TabToolPanel::addSeparator()
{
	_pLayout->removeItem(_pSpacer);
	QGridLayout* pLayoutLine = new QGridLayout;
	pLayoutLine->setContentsMargins(0, 9, 0, 9);
	auto pLine = new QFrame;
	pLine->setObjectName("SeparatorLine");
	pLine->setFrameShape(QFrame::VLine);
	pLine->setFrameShadow(QFrame::Plain);
	pLayoutLine->addWidget(pLine);
	_pLayout->addLayout(pLayoutLine);
	_pLayout->addSpacerItem(_pSpacer);
}