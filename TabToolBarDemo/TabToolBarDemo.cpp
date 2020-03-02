#include "TabToolBarDemo.h"
#include <QGridLayout>
#include <QToolButton>
#include <QApplication>
#include "TabToolBar.h"
#include "TabToolPanel.h"
#include "ToolBox.h"

using namespace VQS;

TabToolBarDemo::TabToolBarDemo(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* layout = new QVBoxLayout;
	auto bar = new TabToolBar;
	auto panel = new TabToolPanel;

	auto box = new ToolBox(QStringLiteral("文件选项"));
	auto btnopen = new QToolButton;
	btnopen->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/folder.png"));
	btnopen->setText(QStringLiteral("新建工程"));
	box->addToolAction(btnopen);
	box->addSeparator();

	auto btnnew = new QToolButton;
	btnnew->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell.png"));
	btnnew->setText(QStringLiteral("新建文件"));
	auto btnclose = new QToolButton;
	btnclose->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell_add.png"));
	btnclose->setText(QStringLiteral("关闭文件"));
	auto btnsave = new QToolButton;
	btnsave->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell_delete.png"));
	btnsave->setText(QStringLiteral("保存文件"));
	QList<QWidget*> btns;
	btns << btnnew << btnclose << btnsave;
	box->addToolActions(btns);

	panel->addPanelBox(box);
	panel->addSeparator();

	auto pboxEdit = new ToolBox(QStringLiteral("编辑选项"));
	QList<QWidget*> boxs;
	boxs << new QCheckBox(QStringLiteral("显示扩展名"));
	boxs << new QCheckBox(QStringLiteral("显示后缀名"));
	auto combox = new QComboBox;
	combox->addItem(QStringLiteral("宋体"));
	combox->addItem(QStringLiteral("楷体"));
	combox->addItem(QStringLiteral("微软雅黑"));
	boxs << combox/*new QCheckBox(QStringLiteral("项目复选框"))*/;
	pboxEdit->addToolActions(boxs);
	panel->addPanelBox(pboxEdit);
	panel->addSeparator();

	bar->addToolPanel(panel, QStringLiteral("文件"));
	bar->addToolPanel(new TabToolPanel, QStringLiteral("编辑"));
	layout->addWidget(bar, 1);
	layout->addWidget(new QWidget, 10);
	layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(layout);
}
