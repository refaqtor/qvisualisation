/****************************************************************************
** This software is released under the MIT license
** Copyright (C) 2016 Yiming Yan
****************************************************************************/
#include <visualisation/core/visualisationdatamodel.h>

#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
using namespace Visualisation;

VisualisationDataModel::VisualisationDataModel(QObject *parent)
    : QObject(parent)
{

}

/*!
 * \brief Recommanded function for setting data and names.
 */
void VisualisationDataModel::setData(const QVector<QVector<qreal> > &data, const QStringList &names)
{
    if(data.size() < 1 || names.size() < 1) {
        return;
    }
    for(int i=0; i<data.size(); ++i) {
        if(data[i].size() != names.size()) {
            return;
        }
    }
    m_data = data;
    m_names = names;
    generateDataJsonDocument();
    emit dataChanged();
    emit namesChanged();
}

void VisualisationDataModel::setData(const QVector<QVector<qreal> > &data)
{
    if(data.size() < 1) {
        return;
    }
    if(m_names.size() > 0) {
        for(int i=0; i<data.size(); ++i) {
            if(data[i].size() != m_names.size()) {
                return;
            }
        }
    }
    m_data = data;
    generateDataJsonDocument();
    emit dataChanged();
}

void VisualisationDataModel::setNames(const QStringList &names)
{
    if(names.size() < 1) {
        return;
    }
    if(m_data.size() > 0) {
        for(int i=0; i<m_data.size(); ++i) {
            if(m_data[i].size() != names.size()) {
                return;
            }
        }
    }
    m_names = names;
    generateDataJsonDocument();
    emit namesChanged();
}

QStringList VisualisationDataModel::allNames() const
{
    return m_names;
}

QJsonDocument VisualisationDataModel::dataJson() const
{
    return m_dataJson;
}

int VisualisationDataModel::dataRows() const
{
    return m_data.size();
}

int VisualisationDataModel::dataCols() const
{
    int size  = 0;
    if(dataRows() > 0) {
        size =  m_data[0].size();
    }
    return size;
}

void VisualisationDataModel::generateDataJsonDocument()
{
    QJsonArray jsonArray;
    for(int i=0; i<m_data.size(); ++i) {
        QJsonObject object;
        for(int j=0; j<m_names.size(); ++j) {
            object[m_names[j]] = m_data[i][j];
        }
        jsonArray.append(object);
    }
    m_dataJson.setArray(jsonArray);
}

QVariantList VisualisationDataModel::selectedIndices() const
{
    return m_selectedIndices;
}

void VisualisationDataModel::setSelectedIndices(const QVariantList &selectedIndices)
{
    m_selectedIndices = selectedIndices;
    emit selectedIndicesChanged();
}
