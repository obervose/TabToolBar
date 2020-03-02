#pragma once

#include "tabtoolbar_global.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QToolButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
/*
	默认的ToolBox 是水平排列的
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
		//!默认添加先后为顺序
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
