/**
 * Autogenerated by Thrift Compiler (0.16.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "calculator_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Tutorial {


CalDesc::~CalDesc() noexcept {
}


void CalDesc::__set_id(const int32_t val) {
  this->id = val;
}

void CalDesc::__set_op(const std::string& val) {
  this->op = val;
}

void CalDesc::__set_num1(const int32_t val) {
  this->num1 = val;
}

void CalDesc::__set_num2(const int32_t val) {
  this->num2 = val;
}
std::ostream& operator<<(std::ostream& out, const CalDesc& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t CalDesc::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->op);
          this->__isset.op = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->num1);
          this->__isset.num1 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->num2);
          this->__isset.num2 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t CalDesc::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("CalDesc");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("op", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->op);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("num1", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->num1);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("num2", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->num2);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(CalDesc &a, CalDesc &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.op, b.op);
  swap(a.num1, b.num1);
  swap(a.num2, b.num2);
  swap(a.__isset, b.__isset);
}

CalDesc::CalDesc(const CalDesc& other0) {
  id = other0.id;
  op = other0.op;
  num1 = other0.num1;
  num2 = other0.num2;
  __isset = other0.__isset;
}
CalDesc& CalDesc::operator=(const CalDesc& other1) {
  id = other1.id;
  op = other1.op;
  num1 = other1.num1;
  num2 = other1.num2;
  __isset = other1.__isset;
  return *this;
}
void CalDesc::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "CalDesc(";
  out << "id=" << to_string(id);
  out << ", " << "op=" << to_string(op);
  out << ", " << "num1=" << to_string(num1);
  out << ", " << "num2=" << to_string(num2);
  out << ")";
}

} // namespace
