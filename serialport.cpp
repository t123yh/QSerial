#include "serialport.h"
#include "serialportqt.h"
#include "serialportdummy.h"
#include <QSerialPortInfo>

SerialPort::SerialPort(QObject *parent) : QObject(parent) {}

QList<SerialPort *> SerialPort::getAvailablePorts(QObject *parent) {
  QList<SerialPort *> result;
  auto ports = QSerialPortInfo::availablePorts();
  for (auto port : ports) {
    result.append(new SerialPortQt(parent, port.portName()));
  }
  result.append(new SerialPortDummy(parent));

  return result;
}