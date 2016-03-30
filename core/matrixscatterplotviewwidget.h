/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2015 Yiming Yan
****************************************************************************/
#ifndef MATRIXSCATTERPLOTVIEWWIDGET_H
#define MATRIXSCATTERPLOTVIEWWIDGET_H
#include <visualisation/core/visualisationviewwidget.h>

namespace Visualisation {

class MatrixScatterPlotViewWidget : public VisualisationViewWidget
{
public:
    explicit MatrixScatterPlotViewWidget(QWidget *parent = 0);
    void initialise();
};

}
#endif // MATRIXSCATTERPLOTVIEWWIDGET_H
