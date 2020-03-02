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

	auto box = new ToolBox(QStringLiteral("�ļ�ѡ��"));
	auto btnopen = new QToolButton;
	btnopen->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/folder.png"));
	btnopen->setText(QStringLiteral("�½�����"));
	box->addToolAction(btnopen);
	box->addSeparator();

	auto btnnew = new QToolButton;
	btnnew->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell.png"));
	btnnew->setText(QStringLiteral("�½��ļ�"));
	auto btnclose = new QToolButton;
	btnclose->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell_add.png"));
	btnclose->setText(QStringLiteral("�ر��ļ�"));
	auto btnsave = new QToolButton;
	btnsave->setIcon(QIcon(qApp->applicationDirPath() + "/../resource/icon/bell_delete.png"));
	btnsave->setText(QStringLiteral("�����ļ�"));
	QList<QWidget*> btns;
	btns << btnnew << btnclose << btnsave;
	box->addToolActions(btns);

	panel->addPanelBox(box);
	panel->addSeparator();

	auto pboxEdit = new ToolBox(QStringLiteral("�༭ѡ��"));
	QList<QWidget*> boxs;
	boxs << new QCheckBox(QStringLiteral("��ʾ��չ��"));
	boxs << new QCheckBox(QStringLiteral("��ʾ��׺��"));
	auto combox = new QComboBox;
	combox->addItem(QStringLiteral("����"));
	combox->addItem(QStringLiteral("����"));
	combox->addItem(QStringLiteral("΢���ź�"));
	boxs << combox/*new QCheckBox(QStringLiteral("��Ŀ��ѡ��"))*/;
	pboxEdit->addToolActions(boxs);
	panel->addPanelBox(pboxEdit);
	panel->addSeparator();

	bar->addToolPanel(panel, QStringLiteral("�ļ�"));
	bar->addToolPanel(new TabToolPanel, QStringLiteral("�༭"));
	layout->addWidget(bar, 1);
	layout->addWidget(new QWidget, 10);
	layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(layout);
}
