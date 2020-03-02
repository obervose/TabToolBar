#include "TabToolBar.h"
#include <QApplication>

using namespace VQS;

TabToolBar::TabToolBar(QWidget *parent)
	: QTabWidget(parent)
{
	
	_pBtnShowCorner = new QToolButton;
	_pBtnShowCorner->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bullet_arrow_top.png"));
	_pBtnShowCorner->setText(QStringLiteral("展开"));
	_pBtnShowCorner->setIconSize(QSize(30, 30));
	_pBtnShowCorner->setCheckable(true);
	_pBtnShowCorner->setChecked(false);
	this->setCornerWidget(_pBtnShowCorner, Qt::TopRightCorner);
	this->setObjectName("TabToolNavigationBar");
	this->setFixedHeight(150);
	initConnection();
}

TabToolBar::~TabToolBar()
{

}

void TabToolBar::addToolPanel(QWidget* panel, QString panelName)
{
	this->addTab(panel, panelName);
}

void TabToolBar::initConnection()
{
	connect(_pBtnShowCorner, SIGNAL(clicked(bool)), this, SLOT(onBtnShowCornerClicked(bool)));
}

void TabToolBar::onBtnShowCornerClicked(bool clicked)
{
	if (!clicked)
	{
		_pBtnShowCorner->setIcon(QIcon(qApp->applicationDirPath()+"/../resource/icon/bullet_arrow_top.png"));
		_pBtnShowCorner->setText(QStringLiteral("收起"));
		this->setFixedHeight(150);
	}
	else
	{
		_pBtnShowCorner->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bullet_arrow_bottom.png"));
		_pBtnShowCorner->setText(QStringLiteral("展开"));
		this->setFixedHeight(30);
	}
}
