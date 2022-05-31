//
// Created by Administrator on 2022/5/31.
//

#include "FunnyJsonObject.h"

FunnyJsonArray::Iterator::Iterator(FunnyJsonArray::Iterator::pointer p) : ptr(p) {

}

FunnyJsonArray::Iterator &FunnyJsonArray::Iterator::operator=(const FunnyJsonArray::Iterator &it) {
    ptr = it.ptr;
}

bool FunnyJsonArray::Iterator::operator==(const FunnyJsonArray::Iterator &it) const {
    return ptr == it.ptr;
}

bool FunnyJsonArray::Iterator::operator!=(const FunnyJsonArray::Iterator &it) const {
    return ptr != it.ptr;
}

FunnyJsonArray::Iterator &FunnyJsonArray::Iterator::operator++() {
    ptr++;
    return *this;
}

FunnyJsonArray::Iterator FunnyJsonArray::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

FunnyJsonArray::Iterator &FunnyJsonArray::Iterator::operator--() {
    ptr--;
    return *this;
}

FunnyJsonArray::Iterator FunnyJsonArray::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
};

FunnyJsonValue &FunnyJsonArray::Iterator::operator*() {
    return *ptr;
}

FunnyJsonArray::Iterator FunnyJsonArray::begin() {
    FunnyJsonValue* head = &this->valueArray[0];
    return {head};
}

FunnyJsonArray::Iterator FunnyJsonArray::end() {
    FunnyJsonValue* head = &this->valueArray[0];
    return {head + this->valueArray.size()};
}

string FunnyJsonValue::toString(bool &success) {
    return nullptr;
}

int FunnyJsonValue::toInt(bool &success) {
    return 0;
}

double FunnyJsonValue::toDouble(bool &success) {
    return 0;
}

bool FunnyJsonValue::toBool(bool &success) {
    return false;
}

FunnyJsonArray FunnyJsonValue::toArray(bool &success) {
    return FunnyJsonArray();
}

FunnyJsonObject FunnyJsonValue::toObject(bool &success) {
    return FunnyJsonObject();
}

bool FunnyJsonValue::isNull() {
    return false;
}

bool FunnyJsonValue::isNumber() {
    return false;
}

bool FunnyJsonValue::isObject() {
    return false;
}

bool FunnyJsonValue::isArray() {
    return false;
}

bool FunnyJsonValue::isBool() {
    return false;
}

bool FunnyJsonValue::isString() {
    return false;
}

FunnyJsonValue::FunnyJsonValue() : valueType(FunnyJson::JSON_NULL) {

}

FunnyJsonValue::FunnyJsonValue(int value) : valueType(FunnyJson::JSON_NUMBER) {
    iValue = value;
}

FunnyJsonValue::FunnyJsonValue(double value) : valueType(FunnyJson::JSON_NUMBER) {
    dValue = value;
}

FunnyJsonValue::FunnyJsonValue(bool value) : valueType(FunnyJson::JSON_BOOL) {
    bValue = value;
}

FunnyJsonValue::FunnyJsonValue(string value) : valueType(FunnyJson::JSON_STRING) {
    sValue = std::move(value);
}

FunnyJsonValue::FunnyJsonValue(FunnyJsonArray value) : valueType(FunnyJson::JSON_ARRAY) {
    arrayValue = std::move(value);
}

FunnyJsonValue::FunnyJsonValue(FunnyJsonObject value) : valueType(FunnyJson::JSON_OBJECT) {
    objValue = std::move(value);
}

FunnyJsonObject::FunnyJsonObject() {

}

void FunnyJsonObject::insert(string key, int value) {
    FunnyJsonValue jsonValue(value);
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insert(string key, double value) {
    FunnyJsonValue jsonValue(value);
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insert(string key, string value) {
    FunnyJsonValue jsonValue(std::move(value));
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insert(string key, bool value) {
    FunnyJsonValue jsonValue(value);
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insert(string key, FunnyJsonArray value) {
    FunnyJsonValue jsonValue(std::move(value));
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insert(string key, FunnyJsonObject value) {
    FunnyJsonValue jsonValue(std::move(value));
    this->obj[std::move(key)] = jsonValue;
}

void FunnyJsonObject::insertNull(string key) {
    FunnyJsonValue jsonValue;
    this->obj[std::move(key)] = jsonValue;
}
