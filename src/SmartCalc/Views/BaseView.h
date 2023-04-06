#ifndef BASEVIEW_H
#define BASEVIEW_H

#include "QWidget"
#include "QMainWindow"


class BaseView;
class IPlatformUI;


class BaseView : public QWidget
{

    Q_OBJECT

public:
    BaseView(IPlatformUI *platform) : _platformUi(platform){ }

    void RetranslateUI(QWidget *MainWindow);
    void SetupUI(QWidget *MainWindow);

protected:
    IPlatformUI *_platformUi;
};




class IPlatformUI
{
public:
    IPlatformUI() {}
    void RetranslateUI(BaseView *MainWindow);
    void SetupUI(BaseView *MainWindow);
};


#endif // BASEVIEW_H
