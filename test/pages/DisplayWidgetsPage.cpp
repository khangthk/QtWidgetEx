#include "DisplayWidgetsPage.h"
#include "DisplayWidgetsPage_p.h"

#include "../utils/RunnableHandler.h"

DisplayWidgetsPage::DisplayWidgetsPage(QWidget* parent)
	: LifeCycleWidget(*new DisplayWidgetsPagePrivate, parent)
{
	Q_D(DisplayWidgetsPage);
	d->init();
}

DisplayWidgetsPage::~DisplayWidgetsPage() {
}

bool DisplayWidgetsPage::attempClose() {
	return true;
}

void DisplayWidgetsPage::onNavigateResult(const QVariant& data) {}

void DisplayWidgetsPage::onViewLoad() {}

void DisplayWidgetsPage::onReshow() {}

void DisplayWidgetsPage::onHidden() {}

void DisplayWidgetsPage::onResizeWindow() {}

void DisplayWidgetsPagePrivate::init() {
	Q_Q(DisplayWidgetsPage);
	bindView(q);
}

void DisplayWidgetsPagePrivate::setLabelExTextTest() {
	useConverter(false);
    if (setInThread()) {
		RunnableHandler<void>::exec([&] {
			setLabelExText("set text in work thread!");
		});
    } else {
		setLabelExText("set text finished!");
    }
}

void DisplayWidgetsPagePrivate::setLabelExTextTestByConverter() {
	useConverter(true);
	if (setInThread()) {
		RunnableHandler<void>::exec([&] {
			setLabelExTextByConverter({ 0, "set data in work thread!" });
		});
	} else {
		setLabelExTextByConverter({ 1, "set data finished!" });
	}
}

