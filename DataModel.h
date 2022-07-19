#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QModbusDataUnit>
#include "modbusmanager.h"

class DataModel : public QAbstractListModel
{
    Q_OBJECT
public:

  enum Roles{
      listARole = Qt::UserRole,
      listBRole
  };

    DataModel(QObject *parent = 0);
    ~DataModel();
    void getData();

    // Model Control

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    //

private :

    modbusmanager* m_modbusmanager;
    QList<QString> m_list;
    QList<QString> m_newlist;
    int m_ready = 0;
    int m_sizelist;

};

#endif // DATAMODEL_H


