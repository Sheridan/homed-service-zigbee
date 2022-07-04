#ifndef PROPERTY_H
#define PROPERTY_H

#include <QMap>
#include <QSharedPointer>
#include <QVariant>

class AttributeObject;
typedef QSharedPointer <AttributeObject> Attribute;

class ClusterObject;
typedef QSharedPointer <ClusterObject> Cluster;

class PropertyObject;
typedef QSharedPointer <PropertyObject> Property;

class AttributeObject
{

public:

    AttributeObject(void) : m_dataType(0) {}

    inline quint8 dataType(void) { return m_dataType; }
    inline void setDataType(quint8 value) { m_dataType = value; }

    inline QByteArray data(void) { return m_data; }
    inline void setData(const QByteArray &value) { m_data = value; }

private:

    quint8 m_dataType;
    QByteArray m_data;

};

class ClusterObject
{

public:

    ClusterObject(void) {}

    inline quint8 commandId(void) { return m_commandId; }
    inline void setCommandId(quint8 value) { m_commandId = value; }

    inline QByteArray commandData(void) { return m_commandData; }
    inline void setCommandData(const QByteArray &value) { m_commandData = value; }

    inline bool commandReceived(void) { return m_commandReceived; }
    inline void setCommandReceived(bool value = true) { m_commandReceived = value; }

    Attribute attribute(quint16 attributeId);

private:

    quint8 m_commandId;
    QByteArray m_commandData;
    bool m_commandReceived;

    QMap <quint16, Attribute> m_attributes;

};

class PropertyObject
{

public:

    PropertyObject(const QString &name, quint16 clusterId) :
        m_clusterId(clusterId), m_name(name) {}

    inline QString name(void) { return m_name; }
    inline quint16 clusterId(void) { return m_clusterId; }
    inline QVariant value(void) { return m_value; }

    virtual void parse(const Cluster &cluster) = 0;

protected:

    quint16 m_clusterId;
    QString m_name;
    QVariant m_value;

};

namespace Properties
{
    class BatteryVoltage : public PropertyObject
    {

    public:

        BatteryVoltage(void);
        virtual ~BatteryVoltage(void) {}
        void parse(const Cluster &cluster) override;

    };

    class BatteryPercentage : public PropertyObject
    {

    public:

        BatteryPercentage(void);
        virtual ~BatteryPercentage(void) {}
        void parse(const Cluster &cluster) override;

    };

    class BatteryIKEA : public PropertyObject
    {

    public:

        BatteryIKEA(void);
        virtual ~BatteryIKEA(void) {}
        void parse(const Cluster &cluster) override;

    };

    class BatteryLUMI : public PropertyObject
    {

    public:

        BatteryLUMI(void);
        virtual ~BatteryLUMI(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Status : public PropertyObject
    {

    public:

        Status(void);
        virtual ~Status(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Level : public PropertyObject
    {

    public:

        Level(void);
        virtual ~Level(void) {}
        void parse(const Cluster &cluster) override;

    };

    class ColorTemperature : public PropertyObject
    {

    public:

        ColorTemperature(void);
        virtual ~ColorTemperature(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Illuminance : public PropertyObject
    {

    public:

        Illuminance(void);
        virtual ~Illuminance(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Temperature : public PropertyObject
    {

    public:

        Temperature(void);
        virtual ~Temperature(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Humidity : public PropertyObject
    {

    public:

        Humidity(void);
        virtual ~Humidity(void) {}
        void parse(const Cluster &cluster) override;

    };

    class Occupancy : public PropertyObject
    {

    public:

        Occupancy(void);
        virtual ~Occupancy(void) {}
        void parse(const Cluster &cluster) override;

    };

    class CubeAction : public PropertyObject
    {

    public:

        CubeAction(void);
        virtual ~CubeAction(void) {}
        void parse(const Cluster &cluster) override;

    };

    class SwitchAction : public PropertyObject
    {

    public:

        SwitchAction(void);
        virtual ~SwitchAction(void) {}
        void parse(const Cluster &cluster) override;

    };

    class SwitchActionPTVO : public PropertyObject
    {

    public:

        SwitchActionPTVO(void);
        virtual ~SwitchActionPTVO(void) {}
        void parse(const Cluster &cluster) override;

    };

    class SwitchActionLUMI : public PropertyObject
    {

    public:

        SwitchActionLUMI(void);
        virtual ~SwitchActionLUMI(void) {}
        void parse(const Cluster &cluster) override;

    };

    class LevelAction : public PropertyObject
    {

    public:

        LevelAction(void);
        virtual ~LevelAction(void) {}
        void parse(const Cluster &cluster) override;

    };
}

#endif
