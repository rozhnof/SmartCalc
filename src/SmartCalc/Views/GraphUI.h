#ifndef GRAPHUI_H
#define GRAPHUI_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class GraphUI;
}

class GraphUI : public QWidget
{
    Q_OBJECT

public:
    explicit GraphUI(QWidget *parent = nullptr);
    ~GraphUI();


private:
    Ui::GraphUI *ui;
    QCustomPlot *graph;

private slots:
    void DrawLine();
};

#endif // GRAPHUI_H
