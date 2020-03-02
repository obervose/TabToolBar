#pragma once

#include "tabtoolbar_global.h"
#include <QFrame>
#include <QHBoxLayout>
#include "ToolBox.h"

namespace VQS
{
	class TABTOOLBAR_EXPORT TabToolPanel : public QFrame
	{
		Q_OBJECT

	public:
		TabToolPanel(QWidget *parent = nullptr);
		~TabToolPanel();

		void addPanelBox(QString str);
		void addPanelBox(ToolBox* box);
		void addSeparator();
	private:
		QHBoxLayout *_pLayout;
		QSpacerItem *_pSpacer;
	};

}
