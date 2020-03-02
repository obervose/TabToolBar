#pragma once

#include "tabtoolbar_global.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QToolButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
/*
	Ĭ�ϵ�ToolBox ��ˮƽ���е�
*/
namespace VQS
{
	class TABTOOLBAR_EXPORT ToolBox : public QFrame
	{
		Q_OBJECT

	public:
		ToolBox(QWidget *parent = nullptr);
		ToolBox(const QString& caption, QWidget *parent = nullptr);
		~ToolBox();
		void setCaption(const QString &str);
		QString caption();
		//!Ĭ������Ⱥ�Ϊ˳��
		void addToolAction(QWidget* act);
		void addToolActions(QList<QWidget*> &list);
		void addSeparator();
	private:
		void initBox();
	private:
		QString _cpation;
		QHBoxLayout* _pLayout;
		QLabel* _pLabelCaption;
		QSpacerItem *_pSpacer;
	};

}
